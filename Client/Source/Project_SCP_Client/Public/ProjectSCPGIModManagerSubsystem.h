#pragma once

#include "CoreMinimal.h"
#include "ModInfoStruct.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Dom/JsonObject.h"
#include "ProjectSCPGIModManagerSubsystem.generated.h"

UCLASS()
class PROJECT_SCP_CLIENT_API UProjectSCPGIModManagerSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "P-SCP/Modding")
    void Init();

    UFUNCTION(BlueprintCallable, Category = "P-SCP/Modding")
    void ScanForMods();

    UFUNCTION(BlueprintCallable, Category = "P-SCP/Modding")
    void AddModScanDirectory(const FString& NewPath);

    UFUNCTION(BlueprintCallable, Category = "P-SCP/Modding")
    const TArray<FModInfoStruct>& GetAllMods() const { return AllMods; }

private:
    void ScanDirectory(const FString& DirectoryPath);
    void LoadModInfoFromJson(const FString& FilePath);
    void AttemptLoadPlugin(const FString& PluginPath);

    FString WorkshopModsPath;
    FString LocalModsPath;
    FString PaidModsPath;

    TArray<FString> AdditionalModPaths;
    TArray<FModInfoStruct> AllMods;
};