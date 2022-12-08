// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SB_AttackHit.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct SKYBRAWLPROJECT2022_API FSB_AttackHit
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float Damage;

	UPROPERTY(BlueprintReadWrite)
	FVector KnockbackDirection;

	UPROPERTY(BlueprintReadWrite)
	float KnockbackScalar;

	UPROPERTY(BlueprintReadWrite)
	bool bIsLauncher;
};
