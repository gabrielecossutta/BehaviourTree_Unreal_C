// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTEnemySearchBall.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOURTREEGAME_API UBTTEnemySearchBall : public UBTTaskNode
{
	GENERATED_BODY()
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);


	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector BestBall;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector HasBall;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector BestBallAttached;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Player;
};
