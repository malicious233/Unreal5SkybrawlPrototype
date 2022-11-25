// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_Hitbox.h"

#include "CharacterScripts/SB_DamagableInterface.h"
#include "GenericPlatform/GenericPlatformCrashContext.h"
#include "UObject/ReferenceChainSearch.h"


// Sets default values
ASB_Hitbox::ASB_Hitbox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Hitbox Collider"));
}

AActor* ASB_Hitbox::GetHitboxOwner()
{
	return HitboxOwner;
}

void ASB_Hitbox::SetHitboxOwner(AActor* NewOwner)
{
	HitboxOwner = NewOwner;
}

void ASB_Hitbox::EndHitbox()
{
	Destroy();
}

void ASB_Hitbox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor->GetClass()->ImplementsInterface(USB_DamagableInterface::StaticClass()))
	{
		//Checks if this hitboxes group  has hit this Actor before, if it hasnt, deal damage and add to the list, if it has hit, exit loop
		bool HasHitBefore = false;
		for (int i = 0; i < HitboxGroupRef->HitRef.Num(); i++)
		{
			if (OtherActor == HitboxGroupRef->HitRef[i])
			{
				HasHitBefore = true;
			}
		}
		if (HasHitBefore == false)
		{

			//The SweepResult from OnOverlapBegin isnt populated with Impact location data so-
			//-we do a second Spherical sweep to get an actual approximate FHitResult instead of an empty one.
			TArray<FHitResult> AllResults;
			
			auto Start = GetActorLocation();
			auto End = OtherComp->GetComponentLocation();
			auto CollisionRadius = FVector::Dist(Start, End) * 1.1f;
			
			FCollisionQueryParams Param;
			
			GetWorld()->SweepMultiByObjectType(
				AllResults,
				Start,
				End,
				FQuat::Identity,
				0,
				FCollisionShape::MakeSphere(CollisionRadius),
				Param
				);

			//Make sure we get check the collision for actually correct hit component
			for (auto HitResult : AllResults)
			{
				if (OtherComp->GetUniqueID() == HitResult.GetComponent()->GetUniqueID()) {
					ISB_DamagableInterface::Execute_DamagePoint(OtherActor, 5, HitResult); //We're doing a copy here, potentially wasteful?
					HitboxGroupRef->HitRef.Add(OtherActor);
					break;
				}
			}
			
			
		}
		
	}
	/* //why this no work :(
	ISB_DamagableInterface* Interface = Cast<ISB_DamagableInterface>(OtherActor);
	if (Interface)
	{
		Interface->Execute_Damage(OtherActor, 5);
		GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
		1.f,
		FColor::Magenta,
		FString::Printf(TEXT("Hi!"))); //Printf returns a string
		
	}
	*/
}


// Called when the game starts or when spawned
void ASB_Hitbox::BeginPlay()
{
	Super::BeginPlay();
	CapsuleCollider->OnComponentBeginOverlap.AddDynamic(this, &ASB_Hitbox::OnOverlapBegin);
	
}

// Called every frame
void ASB_Hitbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

