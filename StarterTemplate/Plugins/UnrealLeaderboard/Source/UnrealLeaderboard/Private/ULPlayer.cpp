// Fill out your copyright notice in the Description page of Project Settings.


#include "ULPlayer.h"

#include "JsonObjectConverter.h"

void FULPlayer::StringJsonToUlPlayers(const FString& JsonString, TArray<FULPlayer>* OutArray)
{
	FJsonObjectConverter::JsonArrayStringToUStruct<FULPlayer>(JsonString, OutArray, 0, 0);
}

void FULPlayer::JsonToUlPlayers(const TArray<TSharedPtr<FJsonValue>>& Json, TArray<FULPlayer>* OutArray)
{
	FJsonObjectConverter::JsonArrayToUStruct<FULPlayer>(Json, OutArray, 0, 0);
}

FULPlayer FULPlayer::StringJsonToUlPlayer(const FString& JsonString)
{
	//Array is necessary to parse JSON
	TArray<FULPlayer> Players;

	//Format manually the json to parse array
	const FString FormattedString = "[" + JsonString + "]";

	FJsonObjectConverter::JsonArrayStringToUStruct<FULPlayer>(FormattedString, &Players, 0, 0);
	if(Players.Num() == 1)
		return Players[0];
	else
		return {};

}
