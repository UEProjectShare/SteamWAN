// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SessionRow.generated.h"

/**
 * 
 */
UCLASS()
class STEAMWAN_API USessionRow : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* ServerName;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* HostUser;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* ConnectionFraction;

	UPROPERTY(BlueprintReadOnly)
		bool Selected = false;

	void Setup(class UMainMenu* InParent, uint32 InIndex);

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* RowButton;

	UPROPERTY()
		class UMainMenu* Parent;

	uint32 Index = -1;

	UFUNCTION()
		void OnClicked();
};
