#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ModInfoStruct.h"
#include "ModInfoAsset.generated.h"

UCLASS(BlueprintType)
class PROJECT_SCP_CLIENT_API UModInfoAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mod Info")
    FModInfoStruct ModInfo;
};
