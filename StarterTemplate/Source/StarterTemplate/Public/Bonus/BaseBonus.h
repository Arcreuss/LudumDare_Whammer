// UnrealEngine Starter template - by TechNet 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseBonus.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDestroy);

UCLASS()
class STARTERTEMPLATE_API ABaseBonus : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseBonus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnDestroy OnDestroy;
	
	UPROPERTY(BlueprintReadOnly)
	int Life = 1; //Number of Hammer hit we need to destroy the bonus

	UFUNCTION(BlueprintCallable)
	void DecreaseLife();

	UFUNCTION(BlueprintCallable)
	void DecreaseLifeByNumber(int HitDmg);
};
