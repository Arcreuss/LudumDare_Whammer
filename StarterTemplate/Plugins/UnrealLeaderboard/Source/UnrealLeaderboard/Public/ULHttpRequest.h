// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpModule.h"
#include "UObject/Object.h"
#include "ULHttpRequest.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRequestResponseReceived,bool, bWasSuccessful, int32, ResponseCode, FString, Response);

/**
 * 
 */
UENUM(BlueprintType)
enum class EHttpMethod : uint8
{
	Get,
	Post,
	Put,
	Delete
};

UCLASS()
class UNREALLEADERBOARD_API UULHttpRequest : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:


	/**
	 * @brief Send a HTTP request to an url
	 * @param Method HTTP method of the request
	 * @param Url Url of the request
	 * @param JsonBody Body data of the request (Usually on POST request)
	 */
	UFUNCTION(BlueprintCallable)
	void ProcessRequest(const EHttpMethod Method, const FString & Url, const FString& JsonBody = "");

	
	/**
	 * @brief Called when a response is received from the URL requested by ProcessRequest method
	 * @param HttpRequest The HTTP request has an object
	 * @param HttpResponse The HTTP response has an object
	 * @param bWasSuccessful True if the request was successful
	 */
	void OnGetResponseReceived(TSharedPtr<IHttpRequest> HttpRequest, TSharedPtr<IHttpResponse> HttpResponse, bool bWasSuccessful);
	
	virtual void Deinitialize() override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;


	static void Deserialize(const FString & Json,TSharedPtr<FJsonObject>& MyJson);
	
	/**
	 * @brief Get a representation of the ENUM parameter as a String
	 * @param Method ENUM corresponding of a HTTP method
	 * @return The String corresponding of the enum
	 */
	FString HttpMethodToString(EHttpMethod Method);

public:
	UPROPERTY(BlueprintAssignable)
	FOnRequestResponseReceived OnRequestResponseReceivedDelegate;
	
private:
	FHttpModule * Http;
	int32 TimeOut = 10;
};
