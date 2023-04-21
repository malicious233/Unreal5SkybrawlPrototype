// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SB_DodgeInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class USB_DodgeInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SKYBRAWLPROJECT2022_API ISB_DodgeInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, Category = "Combat")
	void Dodge();
};
