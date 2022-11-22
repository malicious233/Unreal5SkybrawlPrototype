// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_Hitbox.h"

#include "CharacterScripts/SB_DamagableInterface.h"
#include "GenericPlatform/GenericPlatformCrashContext.h"


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

void ASB_Hitbox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->ImplementsInterface(USB_DamagableInterface::StaticClass()))
	{
		ISB_DamagableInterface::Execute_Damage(OtherActor, 5);
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

