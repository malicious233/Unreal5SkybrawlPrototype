// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkybrawlProject2022Character.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "UObject/Object.h"
#include "SB_NotifyState_FollowupWindow.generated.h"

/**
 * 
 */
UCLASS()
class SKYBRAWLPROJECT2022_API USB_NotifyState_FollowupWindow : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	UAnimMontage* MontageToPlay;

	UPROPERTY(EditAnywhere)
	UDataAsset_AttackData* ActionData;

	UPROPERTY(EditAnywhere)
	EButtonInput FollowupInput = EButtonInput::LIGHT;
	
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	virtual bool ShouldFireInEditor() override;

	UFUNCTION()
	void Followup(EButtonInput ButtonInput);

	UPROPERTY()
	ASkybrawlProject2022Character* OwnerRef;
};
