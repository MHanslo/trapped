// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "DoorController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOM_API UDoorController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void OpenDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
	FRotator OpenDoorRotator = FRotator(0.0, 0.0, 0.0);

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	AActor* Player;
};
