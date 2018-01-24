// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorController.h"

#define OUT

// Sets default values for this component's properties
UDoorController::UDoorController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UDoorController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UDoorController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (GetTotalWeightOnPlate() > TriggerWeight)
	{
		OnOpenRequest.Broadcast();
	}
	else
	{
		OnCloseRequest.Broadcast();
	}
}

float UDoorController::GetTotalWeightOnPlate()
{
	TArray<AActor *> OverlappingActors;
	float weight = 0.f;

	if (PressurePlate)
	{
		PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PressurePlate TriggerVolume is not assigned."));
		return weight;
	}

	for (const auto &Actor : OverlappingActors)
	{
		weight += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return weight;
}
