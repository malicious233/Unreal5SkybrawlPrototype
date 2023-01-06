// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_FSMState.h"

void USB_FSMState::Tick_Implementation(float DeltaTime)
{
}

void USB_FSMState::Enter_Implementation()
{
}

void USB_FSMState::Exit_Implementation()
{
}

USB_FSMState::USB_FSMState()
{
	Owner = Cast<AActor>(GetOuter());
}

FString USB_FSMState::GetStateName()
{
	return StateName; 
}


void USB_FSMState::SetStateName(FString NewName)
{
	StateName = NewName;
}

AActor* USB_FSMState::GetStateOwner()
{
	return Owner;
}
