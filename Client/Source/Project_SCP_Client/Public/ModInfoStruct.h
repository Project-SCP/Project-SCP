#pragma once

#include "CoreMinimal.h"
#include "ModInfoStruct.generated.h"

UENUM(BlueprintType)
enum class EModType : uint8
{
    GameMode,
    Addon,
    MapPack,
    AssetPack,
    UIExtension,
    Utility,
    Unknown
};

USTRUCT(BlueprintType)
struct FModDependency
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ModName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RequiredVersion;
};

USTRUCT(BlueprintType)
struct FModInfoStruct
{
    GENERATED_BODY()

    // Core Identifiers
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ModName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ModVersion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Author;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EntryLevel; // Optional: map to load

    // Compatibility
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> SupportedClientVersions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BuiltForClientVersion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EModType ModType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FModDependency> ModDependencies;

    // Runtime Behavior
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsBuiltAsPlugin = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RequiresRestart = false;

    // Optional Display
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ThumbnailPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WebsiteURL;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString License;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Category;

    // Local Paths (runtime only, not serialized)
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient)
    FString ModRootPath;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient)
    FString PluginPath;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient)
    FString JsonSourcePath;

    // Internal Use
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient)
    bool bIsValid = false;
};
