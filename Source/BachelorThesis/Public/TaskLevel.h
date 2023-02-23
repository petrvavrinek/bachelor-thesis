#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TaskLevel.generated.h"

USTRUCT(BlueprintType)
struct FTaskLevel: public FTableRowBase {

	FTaskLevel()
	{ }

	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UWorld> Level;
};