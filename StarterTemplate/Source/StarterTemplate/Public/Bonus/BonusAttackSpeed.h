// UnrealEngine Starter template - by TechNet 2023

#pragma once

#include "CoreMinimal.h"
#include "BaseBonus.h"
#include "GameFramework/Actor.h"
#include "BonusAttackSpeed.generated.h"

UCLASS()
class STARTERTEMPLATE_API ABonusAttackSpeed : public ABaseBonus
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABonusAttackSpeed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
