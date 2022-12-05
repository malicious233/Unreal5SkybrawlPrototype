// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SB_KnockbackInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class USB_KnockbackInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SKYBRAWLPROJECT2022_API ISB_KnockbackInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent,  Category = "Combat")
	void ApplyKnockback(FVector KnockbackDirecton, float KnockbackScalar);
};
