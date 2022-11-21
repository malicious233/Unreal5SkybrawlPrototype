// Fill out your copyright notice in the Description page of Project Settings.


#include "SB_Hitbox.h"


// Sets default values
ASB_Hitbox::ASB_Hitbox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}



// Called when the game starts or when spawned
void ASB_Hitbox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASB_Hitbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

