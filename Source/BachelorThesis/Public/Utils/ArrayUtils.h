// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ArrayUtils.generated.h"

/**
 * 
 */
UCLASS()
class BACHELORTHESIS_API UArrayUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(ArrayParam = "Array"), Category = "Utilities|Array")
	static void ChangeIndexPosition(TArray<UProperty*>& Array, int32 Index, int32 NewIndex);
};
