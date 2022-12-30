// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_NotifyState_JumpWindow.h"

#include "SkybrawlProject2022Character.h"

void USB_NotifyState_JumpWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                             float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	OwnerRef = Cast<ASkybrawlProject2022Character>(MeshComp->GetOwner());

	//If we're input buffering jump as we enter the notifystate, perform jump 
	if (OwnerRef->GetInputBufferDuration() > 0 && OwnerRef->GetLastBufferedInput() == EButtonInput::JUMP)
	{
		OwnerRef->Jump();
		return;
	}
	
	//Listen to input during the entire duration of the Jump window.
	OwnerRef->OnInput.AddDynamic(this, &USB_NotifyState_JumpWindow::Jump);
}

void USB_NotifyState_JumpWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	OwnerRef->OnInput.RemoveDynamic(this, &USB_NotifyState_JumpWindow::Jump);
}

bool USB_NotifyState_JumpWindow::ShouldFireInEditor()
{
	return false;
}

void USB_NotifyState_JumpWindow::Jump(EButtonInput ButtonInput)
{
	if (ButtonInput == EButtonInput::JUMP)
	{
		OwnerRef->Jump();
	}
}
