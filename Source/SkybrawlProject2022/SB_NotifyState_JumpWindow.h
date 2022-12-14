// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "UObject/Object.h"
#include "SB_NotifyState_JumpWindow.generated.h"

enum class EButtonInput : uint8;
class ASkybrawlProject2022Character;
/**
 * 
 */
UCLASS()
class SKYBRAWLPROJECT2022_API USB_NotifyState_JumpWindow : public UAnimNotifyState
{
	GENERATED_BODY()

	UPROPERTY()
	ASkybrawlProject2022Character* OwnerRef;

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	virtual bool ShouldFireInEditor() override;

	UFUNCTION()
	void Jump(EButtonInput ButtonInput);
};
