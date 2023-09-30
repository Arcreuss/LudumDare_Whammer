// UnrealEngine Starter template - by TechNet 2023


#include "LevelActor/RoomManager.h"


// Sets default values
ARoomManager::ARoomManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARoomManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnRoom();
	GetWorldTimerManager().SetTimer(TimerHandle_SpawnWall, this, &ARoomManager::SpawnRoom, 10.0f, true);
}

void ARoomManager::SpawnRoom()
{
	if (RoomToSpawn)
	{
		const auto Room = GetWorld()->SpawnActor<ARoom>(RoomToSpawn, GetActorLocation(), FRotator(0, 0, 0));
	}
}

// Called every frame
void ARoomManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}