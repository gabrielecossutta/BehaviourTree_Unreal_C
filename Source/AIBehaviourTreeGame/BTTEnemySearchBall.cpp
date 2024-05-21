// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTEnemySearchBall.h"
#include "AIBehaviourTreeGameGameMode.h"
#include "Ball.h"
#include "AIBehaviourTreeGameCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
EBTNodeResult::Type UBTTEnemySearchBall::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* controller = OwnerComp.GetAIOwner();
	AAIBehaviourTreeGameCharacter* Enemy = Cast<AAIBehaviourTreeGameCharacter>(controller->GetPawn());
	AGameModeBase* GameMode = controller->GetWorld()->GetAuthGameMode();
	AAIBehaviourTreeGameGameMode* AIGameMode = Cast<AAIBehaviourTreeGameGameMode>(GameMode);
	const TArray<ABall*>& BallsList = AIGameMode->GetBalls();
	AActor* NearlestBall = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BestBall.SelectedKeyName));

	if (NearlestBall)
	{
		NearlestBall->AttachToActor(controller->GetPawn(), FAttachmentTransformRules::KeepRelativeTransform);
		NearlestBall->SetActorRelativeLocation(FVector(0, 0, 0));
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(HasBall.SelectedKeyName, true);
		controller->GetBlackboardComponent()->SetValueAsObject("BestBallAttached", NearlestBall);
	}
	return EBTNodeResult::Type();
}
