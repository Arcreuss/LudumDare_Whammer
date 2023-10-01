// UnrealEngine Starter template - by TechNet 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.generated.h"

UCLASS()
class STARTERTEMPLATE_API ARoom : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARoom();

	UFUNCTION(BlueprintCallable)
	UStaticMeshComponent* GetBoxMesh() const;

	UFUNCTION(BlueprintCallable)
	void SetCount(int NewCount);

	UFUNCTION(BlueprintCallable)
	int GetCount() const;

	UFUNCTION(BlueprintNativeEvent)
	void OnCountChanged();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Array of meshes
	UPROPERTY(EditDefaultsOnly, Category = "C++")
	TArray<TObjectPtr<UStaticMesh>> Meshes;

	// Base Mesh of Room
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly, Category = "C++")
	TObjectPtr<UStaticMeshComponent> BaseMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++")
	int Count = 0;
	
public:
	UPROPERTY(BlueprintReadWrite)
	int32 RandomIndex = FMath::RandRange(0, 2);

	UPROPERTY(BlueprintReadWrite)
	int32 RandomRotation = FMath::RandRange(0, 3);
};
