// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "SkybrawlProject2022Character.h"
#include "UObject/Object.h"
#include "SB_NotifyState_DodgeWindow.generated.h"


/**
 * 
 */
UCLASS()
class SKYBRAWLPROJECT2022_API USB_NotifyState_DodgeWindow : public UAnimNotifyState
{
	GENERATED_BODY()


	UPROPERTY()
	ASkybrawlProject2022Character* OwnerRef;

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
public:

	virtual bool ShouldFireInEditor();

	UFUNCTION()
	void Dodge(EButtonInput ButtonInput);
};
