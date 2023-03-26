// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_FiniteStatemachineComponent.h"


// Sets default values for this component's properties
USB_FiniteStatemachineComponent::USB_FiniteStatemachineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void USB_FiniteStatemachineComponent::SetState(USB_FSMState* ToState)
{
	//Call the functions and event dispatchers on switch
	OnAnyStateExit.Broadcast();
	if (CurrentState != nullptr)
	{
		CurrentState->Exit();
		CurrentState->OnExit.Broadcast();
	}
	
	CurrentState = ToState;
	
	OnAnyStateEnter.Broadcast();
	CurrentState->Enter();
	CurrentState->OnEnter.Broadcast();
	OnAnyStateEnterLate.Broadcast();
	
}

void USB_FiniteStatemachineComponent::SetStateNoExit(USB_FSMState* ToState)
{
	OnAnyStateExit.Broadcast();
	
	CurrentState = ToState;
	
	OnAnyStateEnter.Broadcast();
	CurrentState->Enter();
	CurrentState->OnEnter.Broadcast();
	OnAnyStateEnterLate.Broadcast();
}

USB_FSMState* USB_FiniteStatemachineComponent::GetState()
{
	return CurrentState;
}

// Called when the game starts
void USB_FiniteStatemachineComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USB_FiniteStatemachineComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                    FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentState->Tick(DeltaTime);
	CurrentState->OnTick.Broadcast(DeltaTime);
	//Potentially poorly performant thing we're doing here with running this in tick when we have assigned blueprint events run every frame
}

