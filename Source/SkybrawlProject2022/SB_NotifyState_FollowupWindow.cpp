// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_NotifyState_FollowupWindow.h"

#include "SB_FiniteStatemachineComponent.h"
#include "SB_HitboxManagerComponent.h"
#include "SkybrawlProject2022Character.h"

void USB_NotifyState_FollowupWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                                 float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	OwnerRef = Cast<ASkybrawlProject2022Character>(MeshComp->GetOwner());

	//checks if the buffer duration is over zero and if it is buffering a light attack
	//TODO: The specific input should be configurable

	
	if (OwnerRef->GetInputBufferDuration() > 0 && OwnerRef->GetLastBufferedInput() == FollowupInput) //If buffering an attack input, immediately perform. This will need to be refactored in the future when we have multiple buttons for attacking
	{
		OwnerRef->PerformAttack(ActionData);
		return;
	}
	//OwnerRef->OnAttackInput.AddDynamic(this, &USB_NotifyState_FollowupWindow::PrepareFollowup);
	OwnerRef->OnInput.AddDynamic(this, &USB_NotifyState_FollowupWindow::Followup);
}

void USB_NotifyState_FollowupWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	//OwnerRef->OnAttackInput.RemoveDynamic(this, &USB_NotifyState_FollowupWindow::PrepareFollowup);
	OwnerRef->OnInput.RemoveDynamic(this, &USB_NotifyState_FollowupWindow::Followup);
}

bool USB_NotifyState_FollowupWindow::ShouldFireInEditor()
{
	return false;
}


void USB_NotifyState_FollowupWindow::Followup(EButtonInput ButtonInput)
{
	if (ButtonInput == FollowupInput) 
	{
		OwnerRef->PerformAttack(ActionData);
	}
	
}
