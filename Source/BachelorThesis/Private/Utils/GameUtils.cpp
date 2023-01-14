// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/GameUtils.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/UObjectGlobals.h"
#include "EngineMinimal.h"
// #include "Kismet/BlueprintFunctionLibrary.h"

void UGameUtils::PrintDebugString(const UObject* WorldContextObject, const FString& Content, FLinearColor Color, float Duration)
{
	const FString Prefix = WorldContextObject ? ("[" + WorldContextObject->GetName() + "] ") : "";
	const FString Message = Prefix + Content;
	
	GEngine->AddOnScreenDebugMessage(-1, Duration, Color.ToFColor(false), Message);
}

UObject* UGameUtils::K2_DuplicateObject(UObject* Object)
{
	if (Object == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Could not duplicate object, received nullptr"));
		return nullptr;
	}
	return DuplicateObject(Object, Object->GetOuter());
}
