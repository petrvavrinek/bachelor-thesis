// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameUtils.generated.h"

/**
 * 
 */
UCLASS()
class BACHELORTHESIS_API UGameUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", DefaultToSelf = "WorldContextObject", CallableWithoutWorldContext, AdvancedDisplay = "2"))
	static void PrintDebugString(const UObject* WorldContextObject, const FString& Content, FLinearColor Color = FLinearColor(0, 0.5f, 0.5f), float Duration = 1.f);

	UFUNCTION(BlueprintCallable, Category = "Game|Utils", DisplayName="DuplicateObject")
	static UObject* K2_DuplicateObject(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "Game|Utils")
	static bool RenameObject(UObject* Object, const FString& NewName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Game|Utils")
	static bool GetLevelName(TSoftObjectPtr<UWorld> World, FString& LevelName);
};
