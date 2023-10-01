// UnrealEngine Starter template - by TechNet 2023

#pragma once

#include "CoreMinimal.h"
#include "Room.h"
#include "GameFramework/Actor.h"
#include "RoomManager.generated.h"

UCLASS()
class STARTERTEMPLATE_API ARoomManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARoomManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The room to spawn
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "C++")
	TSubclassOf<ARoom> RoomToSpawn;

	UFUNCTION()
	void OnRoomDestroyed(AActor* DestroyedActor);
	UFUNCTION()
	void SpawnRoom();

	int RoomCount = 1;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};