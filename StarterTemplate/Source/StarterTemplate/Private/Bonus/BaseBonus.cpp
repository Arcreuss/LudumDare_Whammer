// UnrealEngine Starter template - by TechNet 2023


#include "Bonus/BaseBonus.h"


// Sets default values
ABaseBonus::ABaseBonus()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABaseBonus::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseBonus::DecreaseLife()
{
	Life -= 1;
	if (Life <= 0)
	{
		OnDestroy.Broadcast();
	}
}

void ABaseBonus::DecreaseLifeByNumber(int HitDmg)
{
	Life -= HitDmg;
	if (Life <= 0)
	{
		OnDestroy.Broadcast();
	}
}

