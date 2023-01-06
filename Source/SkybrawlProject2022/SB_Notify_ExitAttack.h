// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkybrawlProject2022Character.h"
#include "UObject/Object.h"
#include "SB_Notify_ExitAttack.generated.h"

/**
 * 
 */
UCLASS()
class SKYBRAWLPROJECT2022_API USB_Notify_ExitAttack : public UAnimNotify
{
	GENERATED_BODY()
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	//USB_Notify_ExitAttack();

	virtual bool ShouldFireInEditor();

	UPROPERTY()
	ASkybrawlProject2022Character* CharacterRef;
};
