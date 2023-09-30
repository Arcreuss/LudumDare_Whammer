// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "ULHttpRequest.h"
#include "ULPlayer.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "UObject/Object.h"
#include "ULLeaderboardSubsystem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRequestSend);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetPlayersResponseReceived, const bool, bWasSuccessful, const TArray<FULPlayer> &, Players);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPostPlayerReceived, const bool, bWasSuccessful);







UCLASS()
class UNREALLEADERBOARD_API UULLeaderboardSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Deinitialize() override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;


	UFUNCTION(BlueprintCallable)
	void GetPlayers();

	UFUNCTION(BlueprintCallable)
	void PostPlayer(const FString& Name, const int32 Score);
	
	
	/*
	 * Delegate for every types of request
	 */
	
	UPROPERTY(BlueprintAssignable)
	FOnRequestSend OnRequestSendDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnGetPlayersResponseReceived OnGetPlayersRequestReceivedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnPostPlayerReceived OnPostPlayerRequestReceivedDelegate;


protected:
	
private:

	/*
	 * Responses functions from all types of request
	 */
	UFUNCTION()
	void OnGetPlayersResponseReceived(const bool bWasSuccessful, const int32 ResponseCode, const FString Response);
	
	UFUNCTION()
	void OnPostPlayersResponseReceived(const bool bWasSuccessful, const int32 ResponseCode, const FString Response);
	
	
	UPROPERTY()
	UULHttpRequest * HttpRequestSubsystem;

	//TODO Go to project settings
	UPROPERTY(EditDefaultsOnly)
	FString BaseURL = "http://zankanotachi.pythonanywhere.com";

};


