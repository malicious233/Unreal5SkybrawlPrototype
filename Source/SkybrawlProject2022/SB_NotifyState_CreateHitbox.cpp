// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_NotifyState_CreateHitbox.h"

#include "SB_HitboxManagerComponent.h"

void USB_NotifyState_CreateHitbox::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	OnHitboxEnd.Broadcast();
}

bool USB_NotifyState_CreateHitbox::ShouldFireInEditor()
{
	return false;
}
