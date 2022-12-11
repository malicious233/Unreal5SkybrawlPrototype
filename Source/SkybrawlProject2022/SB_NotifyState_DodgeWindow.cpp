// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_NotifyState_DodgeWindow.h"

void USB_NotifyState_DodgeWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	OwnerRef = Cast<ASkybrawlProject2022Character>(MeshComp->GetOwner());

	OwnerRef->OnEvadeInput.AddDynamic(this, &USB_NotifyState_DodgeWindow::PrepareDodge);
}

void USB_NotifyState_DodgeWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	OwnerRef->OnEvadeInput.RemoveDynamic(this, &USB_NotifyState_DodgeWindow::PrepareDodge);
}

bool USB_NotifyState_DodgeWindow::ShouldFireInEditor()
{
	return false;
}

void USB_NotifyState_DodgeWindow::PrepareDodge()
{
	OwnerRef->OnTryDodge.Broadcast(); //Keeps the logic outside of the NotifyState. TODO: Do the same for Followup Window
}
