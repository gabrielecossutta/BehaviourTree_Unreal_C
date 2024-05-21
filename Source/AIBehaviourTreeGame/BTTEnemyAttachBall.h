// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTEnemyAttachBall.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOURTREEGAME_API UBTTEnemyAttachBall : public UBTTaskNode
{

	GENERATED_BODY()
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector DistanceToBall;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector AttackedBall;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector HasBall;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Player;
};
