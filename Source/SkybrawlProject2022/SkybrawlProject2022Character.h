// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_AttackData.h"
#include "SB_FSMState.h"
#include "CharacterScripts/SB_DamagableInterface.h"
#include "CharacterScripts/SB_KnockbackInterface.h"
#include "GameFramework/Character.h"
#include "SkybrawlProject2022Character.generated.h"


UENUM(BlueprintType)
enum class EButtonInput : uint8
{
	NONE,
	LIGHT,
	HEAVY,
	DODGE,
	JUMP,
};

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
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUsedSignatureOneParam, EButtonInput, ButtonInput);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUsedSignatureTwoParam, FSB_AttackHit, AttackHitResult, FHitResult, HitResult);
	

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnUsedSignatureTwoParam OnDamaged;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnUsedSignatureOneParam OnInput; //On any bufferable action input

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnUsedSignature OnTryDodge;

	/** Statemachine component for splitting up logic */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USB_FiniteStatemachineComponent* StatemachineComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USB_HitboxManagerComponent* HitboxManagerComponent;
	
	ASkybrawlProject2022Character();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	///States, all the StateClasses need to be set///
	//TODO: Make the state objects only settable by the HitboxManagerComponent (via making it a friend)
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

	// KnockedDown
	UPROPERTY(EditDefaultsOnly, Category = "States")
	TSubclassOf<USB_FSMState> KnockedDownStateClass;

	UPROPERTY(BlueprintReadOnly)
	USB_FSMState* KnockedDownState;
	
	// Action (or attacking, synonymous)
	UPROPERTY(EditDefaultsOnly, Category = "States")
	TSubclassOf<USB_FSMState> ActionStateClass;
	
	UPROPERTY(BlueprintReadOnly)
	USB_FSMState* ActionState;
	//

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InputBufferDuration = 0.3;
	
	
	/**
	 * @brief Returns to idle state if grounded and airborne if not grounded
	 */
	UFUNCTION(BlueprintCallable)
	void GoToIdleOrAirborne();

	UFUNCTION(BlueprintCallable)
	void PerformAttack(UDataAsset_AttackData* AttackData);

	//Input Functions

	UFUNCTION()
	void PerformBuffer();
	
	UFUNCTION(BlueprintPure, Category="Input")
	EButtonInput GetLastBufferedInput();

	UFUNCTION(BlueprintPure, Category="Input")
	float GetInputBufferDuration();
	
protected:

	UPROPERTY()
	float LastInputBuffer;

	/** Call before any bufferable actions**/
	void AnyActionInput(EButtonInput ButtonInput);

	/** Called on jump inputs**/
	void JumpInput();

	/** Called on dodge inputs**/
	void DodgeInput();
	
	/** Called on light attack inputs**/
	void LightInput();

	/** Called on heavy attack inputs**/
	void HeavyInput();

	
	
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

	UPROPERTY()
	EButtonInput LastBufferedInput;

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	
};

