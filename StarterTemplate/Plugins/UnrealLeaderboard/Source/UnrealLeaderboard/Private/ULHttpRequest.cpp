// Fill out your copyright notice in the Description page of Project Settings.


#include "ULHttpRequest.h"

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Interfaces/IHttpRequest.h"



void UULHttpRequest::ProcessRequest(const EHttpMethod Method, const FString& Url, const FString& JsonBody)
{
	const TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnGetResponseReceived);
	
	//This is the url on which to process the request
	Request->SetURL(Url);
	Request->SetVerb(HttpMethodToString(Method));
	//Set header
	{
		Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
		Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
		Request->SetHeader(TEXT("Accepts"), TEXT("application/json"));
		Request->SetHeader(TEXT("Accept-Encoding"), TEXT("identity"));
	}
	if (JsonBody != "")
		Request->SetContentAsString(JsonBody);
	Request->ProcessRequest();
}

void UULHttpRequest::OnGetResponseReceived(TSharedPtr<IHttpRequest> HttpRequest,
	TSharedPtr<IHttpResponse> HttpResponse, bool bWasSuccessful)
{
	if(HttpResponse.IsValid())
		OnRequestResponseReceivedDelegate.Broadcast(bWasSuccessful && HttpResponse->GetResponseCode() == 200,HttpResponse->GetResponseCode(),HttpResponse->GetContentAsString());
	else
		OnRequestResponseReceivedDelegate.Broadcast(false,-1,"");

}

void UULHttpRequest::Deinitialize()
{
	Super::Deinitialize();
}

void UULHttpRequest::Initialize(FSubsystemCollectionBase& Collection)
{
	Http = &FHttpModule::Get();
	Http->SetHttpTimeout(TimeOut);
	Super::Initialize(Collection);
}

void UULHttpRequest::Deserialize(const FString& Json,TSharedPtr<FJsonObject>& MyJson)
{
	const TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
	if (!FJsonSerializer::Deserialize(Reader, MyJson))
	{
		// The deserialization failed, handle this case
		ensureAlwaysMsgf(true,TEXT("Can't Deserialize Json"));
	}
}


FString UULHttpRequest::HttpMethodToString(EHttpMethod Method)
{
	switch(Method)
	{
	case EHttpMethod::Get:
		return "GET";
	case EHttpMethod::Post:
		return "POST";
	case EHttpMethod::Put:
		return "PUT";
	case EHttpMethod::Delete:
		return "DELETE";
	default:
		return "UNKNOWN";
	}
}
