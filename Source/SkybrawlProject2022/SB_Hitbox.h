// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "SB_Hitbox.generated.h"

UCLASS()
class SKYBRAWLPROJECT2022_API ASB_Hitbox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASB_Hitbox();

	//UFUNCTION(BlueprintPure)
	//AActor* GetOwner();

	UPROPERTY()
	UCapsuleComponent* CapsuleCollider;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UPROPERTY()
	//AActor* Owner;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
