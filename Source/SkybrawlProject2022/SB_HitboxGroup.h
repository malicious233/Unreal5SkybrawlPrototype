// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterScripts/SB_DamagableInterface.h"
#include "UObject/Object.h"
#include "SB_HitboxGroup.generated.h"

/**
 * 
 */
UCLASS()
class SKYBRAWLPROJECT2022_API USB_HitboxGroup : public UObject
{
	GENERATED_BODY()

	//Hitboxes have a reference to this object, which keeps track of which enemies this cluster has hit. Essential for clustering hitboxes together
	//Potentially wasteful since this object lifetime is fairly short, potentially creating unneccessary work for the Garbage Collector if many attack clusters get created quickly.

public:
	/**
	 * @brief When a hitbox hits an Actor it will add it to this list, to use as a blacklist to not be able to hit the same enemy over and over.
	 */
	UPROPERTY()
	TArray<AActor*> HitRef; //Perhaps replace this with the DamagableInterface later and potentially encapsulating this value

	UPROPERTY()
	int GroupIndex;
};
