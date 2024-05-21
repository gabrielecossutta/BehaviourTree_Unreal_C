// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_UpdateDistanceToPlayer.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOURTREEGAME_API UBTS_UpdateDistanceToPlayer : public UBTService
{
	GENERATED_BODY()
	UBTS_UpdateDistanceToPlayer();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector SelfActorKey;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Player;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector DistanceToPlayer;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector positionenemy;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector positionplayer;
	//VVVVVVVVVVVV
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector BestBall;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector DistanceToBall;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector PositionBall;

};
