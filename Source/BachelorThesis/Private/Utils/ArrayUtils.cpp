// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/ArrayUtils.h"

void UArrayUtils::ChangeIndexPosition(TArray<UProperty*>& Array, int32 Index, int32 NewIndex)
{
	if (Index == NewIndex) return;
	UProperty* Target = Array[Index];
	const uint8 Increment = NewIndex < Index ? -1 : 1;

	for (int32 k = Index; k != NewIndex; k += Increment)
		Array[k] = Array[k + Increment];

	Array[NewIndex] = Target;
}
