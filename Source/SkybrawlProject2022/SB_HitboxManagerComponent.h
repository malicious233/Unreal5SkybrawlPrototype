// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	 * @brief Resets HitboxGroups to avoid leaking memory
	 */
	UFUNCTION(BlueprintCallable)
	void EndAttack();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

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
	TSubclassOf<ASB_Hitbox> HitboxClass;

	/**
	 * @brief 
	 * @return Spawns a hitbox. Currently Deprecated, use SpawnGroupedHitbox for now
	 */
	UFUNCTION()
	ASB_Hitbox* SpawnHitbox();

	/**
	 * @brief Spawns a hitbox that is part of a group. Same indexes will count as 'one hit'
	 * @param GroupIndex
	 * @return
	 */
	UFUNCTION(BlueprintCallable)
	ASB_Hitbox* SpawnGroupedHitbox(int GroupIndex);
	
};
