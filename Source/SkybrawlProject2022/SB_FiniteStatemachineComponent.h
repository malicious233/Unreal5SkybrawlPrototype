// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SB_FSMState.h"
#include "Components/ActorComponent.h"
#include "SB_FiniteStatemachineComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
///@brief Component which acts like a finite statemachine.
///You can either override the states you're using or bind functions/BP custom events to the "OnX" delegates.
///Remember to instantiate your custom states on the Actor and then set one of those states on BeginPlay.
class SKYBRAWLPROJECT2022_API USB_FiniteStatemachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USB_FiniteStatemachineComponent();

	/**
	 * @brief Tells statemachine to switch state, calling the respective Enter and Exit events while we're at it.
	 * @param ToState 
	 */
	UFUNCTION(BlueprintCallable)
	void SetState(USB_FSMState* ToState);

	UFUNCTION(BlueprintPure)
	USB_FSMState* GetState();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUsedSignature);
	UPROPERTY(BlueprintAssignable)
	FOnUsedSignature OnAnyStateEnter;

	UPROPERTY(BlueprintAssignable)
	FOnUsedSignature OnAnyStateEnterLate;

	UPROPERTY(BlueprintAssignable)
	FOnUsedSignature OnAnyStateExit;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	USB_FSMState* CurrentState;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
