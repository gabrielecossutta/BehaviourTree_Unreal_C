// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Ball.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAIController.generated.h"

UCLASS()
class AIBEHAVIOURTREEGAME_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
protected:


	void BeginPlay() override;
	void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBTAsset;
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BTAsset;
	/// ////////////////
	
	UBlackboardComponent* GetBlackboardComponents();
	UPROPERTY(EditAnywhere)
	ABall* BestBall;
};

