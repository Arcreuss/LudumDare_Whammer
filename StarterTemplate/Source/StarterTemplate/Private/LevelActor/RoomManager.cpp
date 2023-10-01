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
}

void ARoomManager::OnRoomDestroyed(AActor* DestroyedActor)
{
	SpawnRoom();
}

void ARoomManager::SpawnRoom()
{
	if (RoomToSpawn)
	{
		const auto Room = GetWorld()->SpawnActor<ARoom>(RoomToSpawn, GetActorLocation(), FRotator(0, 0, 0));
		Room->SetCount(RoomCount);
		Room->OnCountChanged();
		Room->OnDestroyed.AddDynamic(this, &ARoomManager::OnRoomDestroyed);
		RoomCount++;
	}
}

// Called every frame
void ARoomManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}