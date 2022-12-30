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

	if (OwnerRef->GetInputBufferDuration() > 0 && OwnerRef->GetLastBufferedInput() == FollowupInput) //If buffering an input, perform immediately. Once we get to adding multi-button inputs this might be adjusted
	{
		OwnerRef->PerformAttack(ActionData);
		return;
	}

	//Listen for an event input event as long as we're inside the NotifyState
	OwnerRef->OnInput.AddDynamic(this, &USB_NotifyState_FollowupWindow::Followup);
}

void USB_NotifyState_FollowupWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	//Unsubscribe when we exit NotifyState
	OwnerRef->OnInput.RemoveDynamic(this, &USB_NotifyState_FollowupWindow::Followup);
}

bool USB_NotifyState_FollowupWindow::ShouldFireInEditor()
{
	return false;
}

FString USB_NotifyState_FollowupWindow::GetNotifyName_Implementation() const
{
	return FString("Followup");
}


void USB_NotifyState_FollowupWindow::Followup(EButtonInput ButtonInput)
{
	if (ButtonInput == FollowupInput) 
	{
		OwnerRef->PerformAttack(ActionData);
	}
	
}
