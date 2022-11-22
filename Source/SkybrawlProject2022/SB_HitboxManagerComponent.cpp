// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_HitboxManagerComponent.h"


// Sets default values for this component's properties
USB_HitboxManagerComponent::USB_HitboxManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USB_HitboxManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USB_HitboxManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

ASB_Hitbox* USB_HitboxManagerComponent::SpawnHitbox()
{

	//Perhaps warn if HitboxClass is not set, as it needs to be to not crash. Very careless programming I'm doing
	const FTransform SpawnTransform = FTransform::Identity;
	ASB_Hitbox* Hitbox = GetWorld()->SpawnActor<ASB_Hitbox>(HitboxClass, SpawnTransform);

	Hitbox->SetHitboxOwner(GetOwner());
	return Hitbox;
}

