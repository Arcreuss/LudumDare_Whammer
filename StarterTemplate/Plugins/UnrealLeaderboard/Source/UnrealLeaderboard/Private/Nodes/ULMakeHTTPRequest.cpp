// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/ULMakeHTTPRequest.h"

#include "JsonUtils/JsonPointer.h"

UULMakeHTTPRequest::UULMakeHTTPRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer), WorldContextObject(nullptr), URL("https://example.com/"), JsonBody("")
{
}

void UULMakeHTTPRequest::Activate()
{
	if(!HTTPRequestSubsystem)
	{
		FFrame::KismetExecutionMessage(TEXT("Can't get HTTPRequestSubsystem"), ELogVerbosity::Error);
		return;
	}
		
	HTTPRequestSubsystem->OnRequestResponseReceivedDelegate.AddUniqueDynamic(this,&ThisClass::OnRequestReceived);
	HTTPRequestSubsystem->ProcessRequest(Method,URL,JsonBody);
	Super::Activate();
}

UULMakeHTTPRequest* UULMakeHTTPRequest::MakeHTTPRequest(UObject* WorldContextObject, const FString& URL, const EHttpMethod Method, const FString& JsonBody)
{
	//Initialize all member of the blueprint nodes corresponding to the inputs
	UULMakeHTTPRequest * BlueprintNode = NewObject<UULMakeHTTPRequest>();
	BlueprintNode->WorldContextObject = WorldContextObject;
	BlueprintNode->URL = URL;
	BlueprintNode->Method = Method;
	BlueprintNode->JsonBody = JsonBody;
	if(const auto * GameInstance = WorldContextObject->GetWorld()->GetGameInstance())
		BlueprintNode->HTTPRequestSubsystem = GameInstance->GetSubsystem<UULHttpRequest>();
	return BlueprintNode;
}

void UULMakeHTTPRequest::OnRequestReceived(const bool bWasSuccessful, const int32 ResponseCode, const FString Response)
{
	if(!HTTPRequestSubsystem)
	{
		FFrame::KismetExecutionMessage(TEXT("Can't get HTTPRequestSubsystem"), ELogVerbosity::Error);
		return;
	}
	HTTPRequestSubsystem->OnRequestResponseReceivedDelegate.RemoveDynamic(this,&ThisClass::OnRequestReceived);
	if(bWasSuccessful)
	{
		OnSuccess.Broadcast(ResponseCode,Response);
	}
	else
	{
		OnFailure.Broadcast(ResponseCode,Response);
	}
	
}

