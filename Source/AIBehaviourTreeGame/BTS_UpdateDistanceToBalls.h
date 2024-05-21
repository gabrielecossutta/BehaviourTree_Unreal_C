// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_UpdateDistanceToBalls.generated.h"

/**
 * 
 */
UCLASS()
class AIBEHAVIOURTREEGAME_API UBTS_UpdateDistanceToBalls : public UBTService
{
    GENERATED_BODY()

public:
    UBTS_UpdateDistanceToBalls();

protected:
    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FName Tag;
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector PlayerHasBall;
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector SelfActorKey;
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector Player;
};
