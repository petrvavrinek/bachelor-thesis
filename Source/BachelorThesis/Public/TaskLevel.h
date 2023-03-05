#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Blueprint.h"
#include "TaskLevel.generated.h"

/** There is no way to reference World in the Blueprints, this wrapper should help it */
USTRUCT(BlueprintType)
struct FWorldRef {

	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UWorld> Level;
};