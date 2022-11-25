// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DataAsset_HitboxData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FHitboxPositionInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FVector RotationOffset;

	UPROPERTY(EditAnywhere)
	FVector LocalOffset;

	UPROPERTY(EditAnywhere)
	float Radius;

	UPROPERTY(EditAnywhere)
	float CapsuleHalfHeight;
	
};
UCLASS(Blueprintable, BlueprintType)
class SKYBRAWLPROJECT2022_API UDataAsset_HitboxData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAnimMontage* Montage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FHitboxPositionInfo> HitboxPositionInfos;
};
