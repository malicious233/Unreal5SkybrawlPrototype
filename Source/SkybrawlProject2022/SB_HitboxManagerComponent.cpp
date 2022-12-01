﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_HitboxManagerComponent.h"


// Sets default values for this component's properties
USB_HitboxManagerComponent::USB_HitboxManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void USB_HitboxManagerComponent::EndAttack()
{
	HitboxGroups.Empty(); //Empty list of hitbox groups as not to keep adding data. Should we call clear instead or not?
	CurrentHitboxIndex = 0; //Go back to the first hitbox index until the next action occurs
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

ASB_Hitbox* USB_HitboxManagerComponent::SpawnGroupedHitbox(int GroupIndex)
{
	const FTransform SpawnTransform = FTransform::Identity;
	ASB_Hitbox* Hitbox = GetWorld()->SpawnActor<ASB_Hitbox>(HitboxClass, SpawnTransform);

	//Give hitbox the right data
	Hitbox->AttackData = CurrentAttackData; //Give the hitbox a reference to the data asset
	Hitbox->CurrentHitboxIndex = CurrentHitboxIndex; //Tell the hitbox which index it should read hitbox position data from

	const int HitboxInfoNum = CurrentAttackData->HitboxPositionInfos.Num();
	if (HitboxInfoNum > CurrentHitboxIndex)
	{
		Hitbox->CurrentDamageIndex = CurrentAttackData->HitboxPositionInfos[CurrentHitboxIndex].DamageIndex;
		//Tell the hitbox which index it should read damage data from
	}
	else
	{
		Hitbox->CurrentDamageIndex = CurrentAttackData->HitboxPositionInfos[HitboxInfoNum].DamageIndex;
		//Tell the hitbox to read the last viable data from the array as not to possibly read out of bounds. Perhaps trigger a warning here
		//to tell designers to have the right amount of entries in the AttackData asset.

	}
	
	//Give hitbox a reference to who created the hitbox, being this Actor
	Hitbox->SetHitboxOwner(GetOwner());
	
	//If hitboxmanager dont have a group with this index, create a new one and assign the hitbox the new groupref.
	//If it does exist assign the ref to the one we have, if GroupIndex int matches
	bool DoesHaveGroup = false;
	
	for (int i = 0; i < HitboxGroups.Num(); i++)
	{
		if (HitboxGroups[i]->GroupIndex == GroupIndex) //We could change this to a dictionary where key is the GroupIndex and value the HitboxGroup to prevent this needless loop iteration
		{
			Hitbox->HitboxGroupRef = HitboxGroups[i];
			DoesHaveGroup = true;
			break;
			
		}
	}
	if (DoesHaveGroup == false)
	{
		USB_HitboxGroup* NewHitboxGroup = NewObject<USB_HitboxGroup>(GetOuter());
		NewHitboxGroup->GroupIndex = GroupIndex;
		
		Hitbox->HitboxGroupRef = NewHitboxGroup;
		HitboxGroups.Add(NewHitboxGroup);
	}

	CurrentHitboxIndex++; //Increment so next hitbox in the action gets the right data
	
	return Hitbox;
}

