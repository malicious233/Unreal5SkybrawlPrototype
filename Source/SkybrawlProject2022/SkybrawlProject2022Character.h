// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_AttackData.h"
#include "SB_FSMState.h"
#include "CharacterScripts/SB_DamagableInterface.h"
#include "CharacterScripts/SB_KnockbackInterface.h"
#include "GameFramework/Character.h"
#include "SkybrawlProject2022Character.generated.h"

UCLASS(config=Game)
class ASkybrawlProject2022Character : public ACharacter, public ISB_DamagableInterface, public ISB_KnockbackInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUsedSignature);

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnUsedSignature OnAttackInput;

	/** Statemachine component for splitting up logic */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USB_FiniteStatemachineComponent* StatemachineComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USB_HitboxManagerComponent* HitboxManagerComponent;
	
	ASkybrawlProject2022Character();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	///States, all these need to be set///

	//Idle
	UPROPERTY(EditDefaultsOnly, Category = "States")
	TSubclassOf<USB_FSMState> IdleStateClass;

	UPROPERTY(BlueprintReadOnly)
	USB_FSMState* IdleState;
	
	// Airborne
	UPROPERTY(EditDefaultsOnly, Category = "States")
	TSubclassOf<USB_FSMState> AirborneStateClass;

	UPROPERTY(BlueprintReadOnly)
	USB_FSMState* AirborneState;
	
	// Hitstunned
	UPROPERTY(EditDefaultsOnly, Category = "States")
	TSubclassOf<USB_FSMState> HitstunStateClass;

	UPROPERTY(BlueprintReadOnly)
	USB_FSMState* HitstunState;

	// Launched
	UPROPERTY(EditDefaultsOnly, Category = "States")
	TSubclassOf<USB_FSMState> LaunchedStateClass;
	
	UPROPERTY(BlueprintReadOnly)
	USB_FSMState* LaunchedState;
	
	// Action (or attacking, synonymous)
	UPROPERTY(EditDefaultsOnly, Category = "States")
	TSubclassOf<USB_FSMState> ActionStateClass;
	
	UPROPERTY(BlueprintReadOnly)
	USB_FSMState* ActionState;
	//
	
	
	/**
	 * @brief Returns to idle state if grounded and airborne if not grounded
	 */
	UFUNCTION(BlueprintCallable)
	void GoToIdleOrAirborne();

	UFUNCTION(BlueprintCallable)
	void PerformAttack(UDataAsset_AttackData* AttackData);

	UPROPERTY(BlueprintReadWrite)
	float AttackInputBuffer;
	
protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);


protected:

	virtual void BeginPlay() override;
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	
};

