// UnrealEngine Starter template - by TechNet 2023


#include "LevelActor/Room.h"

// Sets default values
ARoom::ARoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
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

