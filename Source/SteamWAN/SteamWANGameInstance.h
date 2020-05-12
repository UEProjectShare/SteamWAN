// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../Plugins/Online/OnlineSubsystem/Source/Public/OnlineSubsystem.h"
#include "../Plugins/Online/OnlineSubsystem/Source/Public/Interfaces/OnlineSessionInterface.h"
#include "UI/SessionMenuInterface.h"
#include "SteamWANGameInstance.generated.h"




/**
 * 
 */
UCLASS()
class STEAMWAN_API USteamWANGameInstance : public UGameInstance, public ISessionMenuInterface
{
	GENERATED_BODY()

public:

	USteamWANGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();

	// Create menu called from the level blueprint
	UFUNCTION(BlueprintCallable)
		void LoadMainMenu();

private:

	// Session
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;


public:

	///// ISessionMenuInterface /////////////////// 
	UFUNCTION()
		void Host(FString ServerName) override;

	UFUNCTION()
		void JoinSession(uint32 Index) override;

	UFUNCTION()
		void EndSession() override;

	UFUNCTION()
		void OpenSessionListMenu() override;
	///// ISessionMenuInterface /////////////////// 



private:

	// Main Menu
	TSubclassOf<class UUserWidget> MenuClass;
	class UMainMenu* MainMenu;

private:

	// Session Events
	FString DesiredServerName;
	void OnCreateSessionComplete(FName SessionName, bool Success);
	void OnDestroySessionComplete(FName SessionName, bool Success);
	void OnFindSessionsComplete(bool Success);
	void OnJoinSessionsComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	void CreateSession();
	
};
