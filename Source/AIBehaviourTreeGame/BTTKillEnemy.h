// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTKillEnemy.generated.h"

/**
 *
 */
UCLASS()
class AIBEHAVIOURTREEGAME_API UBTTKillEnemy : public UBTTaskNode
{
	GENERATED_BODY()
	UBTTKillEnemy();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector SelfActor;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Player;
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FName Tag;
};
