// Fill out your copyright notice in the Description page of Project Settings.

#include "Utils/GameUtils.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/UObjectGlobals.h"
#include "EngineMinimal.h"
// #include "Kismet/BlueprintFunctionLibrary.h"

void UGameUtils::PrintDebugString(const UObject *WorldContextObject, const FString &Content, FLinearColor Color, float Duration)
{
	const FString Prefix = WorldContextObject ? ("[" + WorldContextObject->GetName() + "] ") : "";
	const FString Message = Prefix + Content;
	GEngine->AddOnScreenDebugMessage(-1, Duration, Color.ToFColor(false), Message);
}

UObject *UGameUtils::K2_DuplicateObject(UObject *Object)
{
	if (Object == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not duplicate object, received nullptr"));
		return nullptr;
	}
	return DuplicateObject(Object, Object->GetOuter());
}

bool UGameUtils::RenameObject(UObject *Object, const FString &NewName)
{
	if (Object == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("Could not rename object, received nullptr"));

	return Object->Rename(*NewName, nullptr, REN_ForceNoResetLoaders);
}

bool UGameUtils::GetLevelName(TSoftObjectPtr<UWorld> World, FString &LevelName)
{
	if (!World.IsValid())
		return false;
	LevelName = FString(World->GetMapName());
	LevelName.RemoveFromStart(World->StreamingLevelsPrefix);
	return true;
}

TArray<AActor *> UGameUtils::GetAllActorsOfClass(AActor *ActorContext, TSubclassOf<AActor> ActorClass)
{
	if (ActorContext == nullptr)
		return {};

	const UWorld *World = ActorContext->GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Log, TEXT("Cannot get world from %s", *ActorContext->GetName()));
		return {};
	}

	TArray<AActor *> OutActors;
	UGameplayStatics::GetAllActorsOfClass(ActorContext, ActorClass, OutActors);
	return OutActors;
}
