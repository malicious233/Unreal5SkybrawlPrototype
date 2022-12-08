// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_AttackData.h"
#include "SB_HitboxGroup.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "SB_Hitbox.generated.h"

UCLASS()
class SKYBRAWLPROJECT2022_API ASB_Hitbox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASB_Hitbox();

	UFUNCTION(BlueprintPure)
	AActor* GetHitboxOwner();

	UFUNCTION(BlueprintCallable)
	void SetHitboxOwner(AActor* NewOwner);

	UFUNCTION(BlueprintCallable)
	void EndHitbox();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleCollider;

	UPROPERTY()
	USB_HitboxGroup* HitboxGroupRef;

	UPROPERTY(BlueprintReadOnly)
	UDataAsset_AttackData* AttackData;

	UPROPERTY(BlueprintReadOnly)
	int CurrentHitboxIndex; //Which hitbox it should pull data from

	UPROPERTY(BlueprintReadOnly)
	int CurrentDamageIndex; //Which damage data array index it should pull data from

	/**
	 * @brief Returns the damage this hitbox deals, taken from the Data Asset
	 * @return 
	 */
	UFUNCTION(BlueprintPure)
	float GetHitboxDamage();

	/**
	 * @brief Get knockback direction from Data Asset, not taken player rotation into account
	 * @return 
	 */
	UFUNCTION(BlueprintPure)
	FVector GetKnockbackDirection();

	/**
	 * @brief Get Knockback scalar from Data asset
	 * @return 
	 */
	UFUNCTION(BlueprintPure)
	float GetKnockbackScalar();

	UFUNCTION(BlueprintPure)
	bool GetbIsLauncher();
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	AActor* HitboxOwner;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
