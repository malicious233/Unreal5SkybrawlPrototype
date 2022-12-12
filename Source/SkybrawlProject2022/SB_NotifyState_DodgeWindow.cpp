// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_NotifyState_DodgeWindow.h"

void USB_NotifyState_DodgeWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	OwnerRef = Cast<ASkybrawlProject2022Character>(MeshComp->GetOwner());

	if (OwnerRef->GetInputBufferDuration() > 0 && OwnerRef->GetLastBufferedInput() == EButtonInput::DODGE)
	{
		OwnerRef->OnTryDodge.Broadcast();
		return;
	}
	//OwnerRef->OnEvadeInput.AddDynamic(this, &USB_NotifyState_DodgeWindow::PrepareDodge);
	OwnerRef->OnInput.AddDynamic(this, &USB_NotifyState_DodgeWindow::Dodge);
}

void USB_NotifyState_DodgeWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	//OwnerRef->OnEvadeInput.RemoveDynamic(this, &USB_NotifyState_DodgeWindow::PrepareDodge);
	OwnerRef->OnInput.RemoveDynamic(this, &USB_NotifyState_DodgeWindow::Dodge);
}

bool USB_NotifyState_DodgeWindow::ShouldFireInEditor()
{
	return false;
}

void USB_NotifyState_DodgeWindow::PrepareDodge()
{
	OwnerRef->OnTryDodge.Broadcast(); //Keeps the logic outside of the NotifyState, though perhaps this isn't the best implementation. TODO: Do the same for Followup Window
}

void USB_NotifyState_DodgeWindow::Dodge(EButtonInput ButtonInput)
{
	if (ButtonInput != EButtonInput::DODGE)
	{
		return;
	}
	OwnerRef->OnTryDodge.Broadcast();
}
