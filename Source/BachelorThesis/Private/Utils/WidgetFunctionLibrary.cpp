// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/WidgetFunctionLibrary.h"

#include "Components/PanelWidget.h"
#include "Components/Widget.h"

/**
 * Source:
 * Copied from UE GitHub: https://github.com/EpicGames/UnrealEngine/blob/56431d660935a3f06563fd8822b50b582b6b15a6/Engine/Source/Runtime/UMG/Private/Components/PanelWidget.cpp#L184
 *
 * Original InsertChildAt function is Editor only
 */
UPanelSlot* UWidgetFunctionLibrary::InsertChildAt(UPanelWidget* Panel, UWidget* Child, int32 Index) {
	UPanelSlot* NewSlot = Panel->AddChild(Child);
	ShiftChild(Panel, Index, Child);
	return NewSlot;
}

void UWidgetFunctionLibrary::ShiftChild(UPanelWidget* Panel, int32 Index, UWidget* Child)
{
	const int32 CurrentIndex = Panel->GetChildIndex(Child);
	auto Slots = Panel->GetSlots();
	Slots.RemoveAt(CurrentIndex);
	Slots.Insert(Child->Slot, FMath::Clamp(Index, 0, Slots.Num()));
	Panel->Modify(true);
}
