#include "ProjectSCPGIModManagerSubsystem.h"
#include "ModInfoStruct.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"
#include "Interfaces/IPluginManager.h"

void UProjectSCPGIModManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("ModManagerSubsystem Initialized"));
}

void UProjectSCPGIModManagerSubsystem::Deinitialize()
{
    Super::Deinitialize();
    UE_LOG(LogTemp, Log, TEXT("ModManagerSubsystem Deinitialized"));
}

void UProjectSCPGIModManagerSubsystem::Init()
{
    const FString Root = FPaths::ProjectSavedDir();
    WorkshopModsPath = Root / TEXT("Mods/Workshop");
    LocalModsPath = Root / TEXT("Mods/Local");
    PaidModsPath = Root / TEXT("Mods/Paid");

    AllMods.Empty();

    ScanForMods();
}

void UProjectSCPGIModManagerSubsystem::ScanForMods()
{
    AllMods.Empty();
    ScanDirectory(WorkshopModsPath);
    ScanDirectory(LocalModsPath);
    ScanDirectory(PaidModsPath);

    for (const FString& CustomPath : AdditionalModPaths)
    {
        ScanDirectory(CustomPath);
    }
}

void UProjectSCPGIModManagerSubsystem::AddModScanDirectory(const FString& NewPath)
{
    if (!AdditionalModPaths.Contains(NewPath))
    {
        AdditionalModPaths.Add(NewPath);
    }
}

void UProjectSCPGIModManagerSubsystem::ScanDirectory(const FString& DirectoryPath)
{
    if (!FPaths::DirectoryExists(DirectoryPath))
    {
        UE_LOG(LogTemp, Warning, TEXT("Directory does not exist: %s"), *DirectoryPath);
        return;
    }

    TArray<FString> FoundFiles;
    IFileManager::Get().FindFilesRecursive(FoundFiles, *DirectoryPath, TEXT("ModInfo.json"), true, false);

    for (const FString& File : FoundFiles)
    {
        LoadModInfoFromJson(File);
    }
}

void UProjectSCPGIModManagerSubsystem::LoadModInfoFromJson(const FString& FilePath)
{
    FString JsonContent;
    if (!FFileHelper::LoadFileToString(JsonContent, *FilePath))
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to read mod file: %s"), *FilePath);
        return;
    }

    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonContent);

    if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to parse JSON in mod file: %s"), *FilePath);
        return;
    }

    FModInfoStruct ModInfo;
    if (!FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &ModInfo, 0, 0))
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to convert JSON to FModInfoStruct: %s"), *FilePath);
        return;
    }

    FString RootPath = FPaths::GetPath(FilePath);
    FString PluginCandidate = RootPath / (ModInfo.ModName + TEXT(".uplugin"));

    ModInfo.ModRootPath = RootPath;
    ModInfo.PluginPath = PluginCandidate;
    ModInfo.JsonSourcePath = FilePath;
    ModInfo.bIsValid = true;

    AllMods.Add(ModInfo);

    if (FPaths::FileExists(PluginCandidate))
    {
        AttemptLoadPlugin(PluginCandidate);
    }

    UE_LOG(LogTemp, Log, TEXT("Loaded mod '%s' from '%s'"), *ModInfo.ModName, *ModInfo.ModRootPath);
}

void UProjectSCPGIModManagerSubsystem::AttemptLoadPlugin(const FString& PluginPath)
{
    if (!FPaths::FileExists(PluginPath))
    {
        UE_LOG(LogTemp, Warning, TEXT("Plugin file does not exist: %s"), *PluginPath);
        return;
    }

    IPluginManager::Get().AddToPluginsList(PluginPath);
    FString PluginName = FPaths::GetBaseFilename(PluginPath);

    TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(PluginName);
    if (Plugin.IsValid())
    {
        UE_LOG(LogTemp, Log, TEXT("Plugin loaded: %s"), *Plugin->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to register plugin: %s"), *PluginPath);
    }
}