// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();
	
	UPROPERTY(EditAnywhere);
	float Speed = 20;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	virtual void Tick(float DeltaTime) override;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
	bool firstLoad = true;

};
