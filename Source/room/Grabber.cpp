// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	PhysicsHandler = GetOwner() -> FindComponentByClass<UPhysicsHandleComponent>();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerVector;
	FRotator PlayerRotator;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerVector, PlayerRotator);

	FVector LineTraceEnd = PlayerVector + PlayerRotator.Vector() * Reach;
	DrawDebugLine(GetWorld(), PlayerVector, LineTraceEnd, FColor(250, 250, 250), false, 0.f, 0, 10.f);

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
			OUT Hit,
			PlayerVector,
			LineTraceEnd,
			FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
			FCollisionQueryParams(FName(TEXT("")), false, GetOwner()));

	AActor * ActorHit = Hit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *ActorHit -> GetName());
	}
}
