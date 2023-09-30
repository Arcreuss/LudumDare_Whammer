// UnrealEngine Starter template - by TechNet 2023


#include "LevelActor/Room.h"

// Sets default values
ARoom::ARoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	BaseMesh->SetupAttachment(RootComponent);
		
}

UStaticMeshComponent* ARoom::GetBoxMesh() const
{
	return BaseMesh;
}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();

	const int32 RandomIndex = FMath::RandRange(0, 2);
	
	if (Meshes[RandomIndex])
		BaseMesh->SetStaticMesh(Meshes[RandomIndex]);
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

