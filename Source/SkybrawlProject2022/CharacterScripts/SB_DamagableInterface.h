// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SB_DamagableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class USB_DamagableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SKYBRAWLPROJECT2022_API ISB_DamagableInterface
{
	GENERATED_BODY()

	
public:
	UFUNCTION(BlueprintNativeEvent, Category="Combat")
	void Damage(float DamageAmount);
};
