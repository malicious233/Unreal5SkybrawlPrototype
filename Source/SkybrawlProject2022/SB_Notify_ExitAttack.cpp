// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_Notify_ExitAttack.h"

#include "SB_FiniteStatemachineComponent.h"

void USB_Notify_ExitAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		
		ASkybrawlProject2022Character* OwnerRef = Cast<ASkybrawlProject2022Character>(MeshComp->GetOwner()); //ugly casts here, perhaps this can be cached once instead of every time we meet this event.
		OwnerRef->GoToIdleOrAirborne();
	}
	
}

bool USB_Notify_ExitAttack::ShouldFireInEditor()
{
	return false;
	
}

