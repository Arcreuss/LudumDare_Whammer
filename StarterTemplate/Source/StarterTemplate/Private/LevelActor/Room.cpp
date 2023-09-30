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
	const int32 RandomRotation = FMath::RandRange(0, 3);
	
	
	if (Meshes[RandomIndex])
		BaseMesh->SetStaticMesh(Meshes[RandomIndex]);
		switch (RandomRotation)
		{
		default :
			BaseMesh->SetRelativeRotation(FRotator(0, 0, 0));
			break;
		case 0:
			BaseMesh->SetRelativeRotation(FRotator(0, 0, 0));
			break;
		case 1:
			BaseMesh->SetRelativeRotation(FRotator(0, 90, 0 ));
			break;
		case 2:
			BaseMesh->SetRelativeRotation(FRotator(0, 180, 0));
			break;
		case 3:
			BaseMesh->SetRelativeRotation(FRotator(0, 270, 0));
			break;
		}
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

