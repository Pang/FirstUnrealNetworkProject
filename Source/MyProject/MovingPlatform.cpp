// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include <format>

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::BeginPlay()
{
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

 void AMovingPlatform::Tick(float DeltaTime)
 {
	 Super::Tick(DeltaTime);

	 if (ActiveTriggers > 0)
	 {
		 if (HasAuthority())
		 {
			 FVector Location = GetActorLocation();
			 float journeyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			 float journeyTravelled = (Location - GlobalStartLocation).Size();


			 if (journeyTravelled >= journeyLength)
			 {
				 FVector swap = GlobalStartLocation;
				 GlobalStartLocation = GlobalTargetLocation;
				 GlobalTargetLocation = swap;
			 }

			 FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			 Location += Speed * DeltaTime * Direction;
			 SetActorLocation(Location);
		 }
	 }
 }


 void AMovingPlatform::AddActiveTrigger()
 {
	 ActiveTriggers++;
 }

 void AMovingPlatform::RemoveActiveTrigger()
 {
	 if (ActiveTriggers > 0)
	 {
		 ActiveTriggers--;
	 }
 }
