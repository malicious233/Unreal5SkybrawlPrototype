// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SB_FSMState.generated.h"

/**
 * 
 */
///@brief State for use in SB_FiniteStatemachineComponents
/// Switch state with the SetState function in said component
UCLASS(Blueprintable, BlueprintType, Abstract)
class SKYBRAWLPROJECT2022_API USB_FSMState : public UObject
{
	
	GENERATED_BODY()

public:
	USB_FSMState();

	UFUNCTION(BlueprintPure)
	FString GetStateName();
	
	void SetStateName(FString NewName);

	UFUNCTION(BlueprintPure)
	AActor* GetStateOwner();
	
	UFUNCTION(BlueprintNativeEvent)
	void Tick(float DeltaTime);

	UFUNCTION(BlueprintNativeEvent)
	void Enter();

	UFUNCTION(BlueprintNativeEvent)
	void Exit();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUsedSignature);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUsedSignatureOneParam, float, DeltaTime);

	/**
	 *
	 * @brief Broadcasted every tick, gives delta time.
	 * Potentially unperformant as it runs assigned blueprint events each tick. If it becomes a performance issue we can replace it with a overridden C++ events
	 */
	UPROPERTY(BlueprintAssignable)
	FOnUsedSignatureOneParam OnTick;

	/**
	 * @brief Broadcasted when you enter a state
	 */
	UPROPERTY(BlueprintAssignable)
	FOnUsedSignature OnEnter;

	/**
	 * @brief Broadcasted when you exit the state
	 */
	UPROPERTY(BlueprintAssignable)
	FOnUsedSignature OnExit;


private:
	UPROPERTY()
	AActor* Owner;

	UPROPERTY()
	FString StateName;
	

	

	
};
