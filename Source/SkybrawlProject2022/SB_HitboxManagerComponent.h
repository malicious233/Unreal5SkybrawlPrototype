// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_AttackData.h"
#include "SB_Hitbox.h"
#include "Components/ActorComponent.h"
#include "SB_HitboxManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SKYBRAWLPROJECT2022_API USB_HitboxManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USB_HitboxManagerComponent();

	/**
	 * @brief Call when a characters attack usually ends. Resets HitboxGroups to avoid leaking memory
	 */
	UFUNCTION(BlueprintCallable)
	void EndAttack();

	/**
	 * @brief Reference to a data asset, all spawned hitboxes will be passed a reference to this data asset.
	 */
	UPROPERTY(BlueprintReadOnly)
	UDataAsset_AttackData* CurrentAttackData;

	/**
	 * @brief Current hitbox in the AttackData asset we're reading data from
	 */
	UPROPERTY(BlueprintReadOnly)
	int CurrentHitboxIndex;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;



	///Hitbox Related Variables///
	
	/**
	 * @brief Array of references for hitboxgroups
	 */
	UPROPERTY()
	TArray<USB_HitboxGroup*> HitboxGroups;
	

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASB_Hitbox> HitboxClass; //This should automatically be set somewhere instead of being set in Blueprint.

	/**
	 * @brief 
	 * @return Spawns a hitbox. Currently Deprecated, use SpawnGroupedHitbox for now
	 */
	UFUNCTION()
	ASB_Hitbox* SpawnHitbox();

	

	/**
	 * @brief Spawns a hitbox that is part of a group. Spawning a hitbox during an action of the same indexes will count as 'one hit' while different indexes will count as seperate hits.
	 * in other words, each index can hit only once per attack, before EndAttack() is called.
	 * @param GroupIndex
	 * @return
	 */
	UFUNCTION(BlueprintCallable)
	ASB_Hitbox* SpawnGroupedHitbox(int GroupIndex);
	
};
