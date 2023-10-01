// UnrealEngine Starter template - by TechNet 2023

#pragma once

#include "CoreMinimal.h"
#include "BSGameInstance.h"
#include "BaseGameInstance.generated.h"

UCLASS()
class STARTERTEMPLATE_API UBaseGameInstance : public UBSGameInstance
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UBaseGameInstance();

	virtual void Init() override;

	virtual void Shutdown() override;
};
