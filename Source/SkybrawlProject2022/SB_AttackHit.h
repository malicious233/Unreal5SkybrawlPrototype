// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SB_AttackHit.generated.h"


UENUM(BlueprintType)
enum HitReaction
{
	Standard, //Standard hitstun
	None, //No reaction at all
	Launch, //Sends them flying backwards
	Pancake //Immediately puts them to a knocked down state
};
/**
 * Struct which features info about a confirmed hit, used for the DamagableInterface
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

	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<HitReaction> hitReaction = HitReaction::Standard;
};
