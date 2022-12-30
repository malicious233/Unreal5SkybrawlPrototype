// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "UObject/Object.h"
#include "SB_NotifyState_CreateHitbox.generated.h"

/**
 * 
 */
UCLASS()
class SKYBRAWLPROJECT2022_API USB_NotifyState_CreateHitbox : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	//Most implementation for this is done in Blueprint
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUsedSignature);

	UPROPERTY(BlueprintAssignable)
	FOnUsedSignature OnHitboxEnd;

	UPROPERTY(BlueprintReadWrite)
	int HitboxGroupIndex;

	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
	virtual bool ShouldFireInEditor() override;
};
