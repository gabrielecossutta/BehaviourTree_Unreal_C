// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIBehaviourTreeGameGameMode.h"

#include "AIBehaviourTreeGameCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	AAIBehaviourTreeGameCharacter* Enemy = Cast<AAIBehaviourTreeGameCharacter>(GetPawn());
	if (Enemy && Enemy->BTAsset)
	{
		RunBehaviorTree(Enemy->BTAsset);
		GetBlackboardComponent()->SetValueAsObject("Player", UGameplayStatics::GetPlayerCharacter(this, 0));
	}
}
void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
UBlackboardComponent* AEnemyAIController::GetBlackboardComponents()
{

	return GetBlackboardComponent();
}
