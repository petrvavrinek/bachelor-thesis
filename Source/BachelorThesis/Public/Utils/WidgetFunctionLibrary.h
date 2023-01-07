// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WidgetFunctionLibrary.generated.h"

class UPanelWidget;
class UWidget;
class UPanelSlot;

/**
 * 
 */
UCLASS()
class BACHELORTHESIS_API UWidgetFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Widgets")
	static UPanelSlot* InsertChildAt(UPanelWidget* Panel, UWidget* Child, int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Widgets")
	static void ShiftChild(UPanelWidget* Panel, int32 Index, UWidget* Child);

};
