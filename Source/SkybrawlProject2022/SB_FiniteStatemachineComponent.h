// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SB_FSMState.h"
#include "Components/ActorComponent.h"
#include "SB_FiniteStatemachineComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
///@brief Component which acts like a finite statemachine. You can either override the states you're using or bind events to the state calls.
///Remember to instantiate your custom states on the Actor and then set one of those states on BeginPlay.
class SKYBRAWLPROJECT2022_API USB_FiniteStatemachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USB_FiniteStatemachineComponent();

	UFUNCTION(BlueprintCallable)
	void SetState(USB_FSMState* ToState);

	UFUNCTION(BlueprintGetter)
	USB_FSMState* GetState();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUsedSignature);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	USB_FSMState* CurrentState;

	
	
	UPROPERTY()
	TArray<FName> StateDelegateName;
	UPROPERTY()
	TArray<UObject*> StateDelegateObjectName;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
