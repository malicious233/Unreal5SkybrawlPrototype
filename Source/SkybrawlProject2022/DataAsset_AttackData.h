// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DataAsset_AttackData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FHitboxPositionInfo
{
	GENERATED_BODY()

	/**
	 * @brief From which HitboxDamageInfos index it should pull damage data from
	 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Damage")
	int DamageIndex = 0;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Position")
	FRotator RotationOffset = FRotator(0, 90, 0);

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Position")
	FVector LocalOffset = FVector::ZeroVector;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Size")
	float Radius = 10.0;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Size")
	float CapsuleHalfHeight = 10.f;
	
};

USTRUCT(BlueprintType)
struct FHitboxDamageInfo
{
	GENERATED_BODY()

	/**
	 * @brief What group this hitbox will be part of. Each index can hit only once per action
	 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Damage")
	int HitboxGroupIndex = 0;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Damage")
	float DamageAmount = 5;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Knockback")
	FVector KnockbackDirection = FVector(1, 0, 0);

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Knockback")
	float KnockbackScalar = 1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Damage")
	bool bIsLauncher = 0;
	
};
UCLASS(Blueprintable, BlueprintType)
class SKYBRAWLPROJECT2022_API UDataAsset_AttackData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAnimMontage* Montage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FHitboxPositionInfo> HitboxPositionInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FHitboxDamageInfo> HitboxDamageInfos;
};
