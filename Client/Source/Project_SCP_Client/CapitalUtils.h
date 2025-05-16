#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CapitalUtils.generated.h"

UCLASS()
class PROJECT_SCP_CLIENT_API UCapitalUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// This will extract all capital letters from the input text
	UFUNCTION(BlueprintPure, Category = "Text|Utilities")
	static FText GetCapitalLetters(const FText& Input);
};
