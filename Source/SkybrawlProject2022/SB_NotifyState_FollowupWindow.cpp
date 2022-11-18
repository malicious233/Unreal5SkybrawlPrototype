// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_NotifyState_FollowupWindow.h"

#include "SB_FiniteStatemachineComponent.h"
#include "SkybrawlProject2022Character.h"

void USB_NotifyState_FollowupWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                                 float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	OwnerRef = Cast<ASkybrawlProject2022Character>(MeshComp->GetOwner());
	OwnerRef->OnAttack.AddDynamic(this, &USB_NotifyState_FollowupWindow::PrepareFollowup);
}

void USB_NotifyState_FollowupWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	OwnerRef->OnAttack.RemoveDynamic(this, &USB_NotifyState_FollowupWindow::PrepareFollowup);
}

bool USB_NotifyState_FollowupWindow::ShouldFireInEditor()
{
	return false;
}

void USB_NotifyState_FollowupWindow::PrepareFollowup()
{
	OwnerRef->StatemachineComponent->SetState(OwnerRef->ActionState);
	OwnerRef->PlayAnimMontage(MontageToPlay, 1, NAME_None);
}
