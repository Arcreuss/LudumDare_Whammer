// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ULPlayer.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FULPlayer
{
	GENERATED_BODY()

	
	UPROPERTY(BlueprintReadWrite)
	FString name = "";
	
	UPROPERTY(BlueprintReadWrite)
	int score = 0;
	

	static void StringJsonToUlPlayers(const FString& JsonString, TArray<FULPlayer>* OutArray);
	static void JsonToUlPlayers(const TArray<TSharedPtr<FJsonValue>>& Json, TArray<FULPlayer>* OutArray);
	static FULPlayer StringJsonToUlPlayer(const FString& JsonString);

};


