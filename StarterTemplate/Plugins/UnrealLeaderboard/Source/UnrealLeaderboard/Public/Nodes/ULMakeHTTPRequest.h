// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ULHttpRequest.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "UObject/Object.h"
#include "ULMakeHTTPRequest.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FResponseDelegate, int32, ResponseCode, FString, Response);

/**
 * 
 */
UCLASS()
class UNREALLEADERBOARD_API UULMakeHTTPRequest : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	UULMakeHTTPRequest(const FObjectInitializer& ObjectInitializer);

public:
	
	/**
	 * @brief This function is triggered when the node execution pins is executed
	 */
	virtual void Activate() override;

	
	/**
	 * @brief 
	 * @param WorldContextObject The current blueprint container object
	 * @param URL Url of the request
	 * @param Method Method of the request
	 * @param JsonBody Body data of the request (Usually on POST request)
	 * @return The instance of the blueprint node
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Flow Control")
	static UULMakeHTTPRequest* MakeHTTPRequest(UObject* WorldContextObject, const FString& URL, const EHttpMethod Method, const FString& JsonBody);

	// Called when the request is a success
	UPROPERTY(BlueprintAssignable)
	FResponseDelegate OnSuccess;

	// Called when the request is a failure
	UPROPERTY(BlueprintAssignable)
	FResponseDelegate OnFailure;

	// Called when the request get an answer
	UFUNCTION()
	void OnRequestReceived(bool bWasSuccessful, int32 ResponseCode, FString Response);
private:

	
	UObject* WorldContextObject;
	FString URL;
	EHttpMethod Method;
	FString JsonBody;
	
	UPROPERTY()
	UULHttpRequest * HTTPRequestSubsystem;
	
};

