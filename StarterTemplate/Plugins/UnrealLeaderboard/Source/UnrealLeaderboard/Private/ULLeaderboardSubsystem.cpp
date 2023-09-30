// Fill out your copyright notice in the Description page of Project Settings.


#include "ULLeaderboardSubsystem.h"

#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "ULPlayer.h"
#include "Interfaces/IHttpResponse.h"

void UULLeaderboardSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UULLeaderboardSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	checkf(GetWorld(),TEXT("Can't get the world"));
	const auto * GameInstance = GetWorld()->GetGameInstance();
	checkf(GameInstance,TEXT("Can't get the game instance"));
	HttpRequestSubsystem = GameInstance->GetSubsystem<UULHttpRequest>();
	checkf(GameInstance,TEXT("Can't get the HTTP Request game instance"));
}

void UULLeaderboardSubsystem::GetPlayers()
{
	HttpRequestSubsystem->OnRequestResponseReceivedDelegate.AddUniqueDynamic(this,&ThisClass::OnGetPlayersResponseReceived);
	OnRequestSendDelegate.Broadcast();

	HttpRequestSubsystem->ProcessRequest(EHttpMethod::Get,BaseURL);
}

void UULLeaderboardSubsystem::PostPlayer(const FString& Name, const int32 Score)
{
	HttpRequestSubsystem->OnRequestResponseReceivedDelegate.AddUniqueDynamic(this,&ThisClass::OnGetPlayersResponseReceived);
	OnRequestSendDelegate.Broadcast();
	HttpRequestSubsystem->ProcessRequest(EHttpMethod::Post,BaseURL,"{\"name\" : \""+Name+"\", \"score\" : \""+FString::FromInt(Score)+"\"}");
}

void UULLeaderboardSubsystem::OnPostPlayersResponseReceived(const bool bWasSuccessful, const int32 ResponseCode,
	const FString Response)
{
	HttpRequestSubsystem->OnRequestResponseReceivedDelegate.RemoveDynamic(this,&ThisClass::OnPostPlayersResponseReceived);
	const bool AllRequestWasSuccessful = bWasSuccessful && ResponseCode == 200;
	

	OnPostPlayerRequestReceivedDelegate.Broadcast(bWasSuccessful);
}

void UULLeaderboardSubsystem::OnGetPlayersResponseReceived(const bool bWasSuccessful, const int32 ResponseCode,
                                                           const FString Response)
{
	HttpRequestSubsystem->OnRequestResponseReceivedDelegate.AddUniqueDynamic(this,&ThisClass::OnGetPlayersResponseReceived);
	
	const bool AllRequestWasSuccessful = bWasSuccessful && ResponseCode == 200;
	TArray<FULPlayer> Players;
	if(AllRequestWasSuccessful)
	{
		FULPlayer::StringJsonToUlPlayers(Response,&Players);
	}
	OnGetPlayersRequestReceivedDelegate.Broadcast(AllRequestWasSuccessful,Players);

    

}




