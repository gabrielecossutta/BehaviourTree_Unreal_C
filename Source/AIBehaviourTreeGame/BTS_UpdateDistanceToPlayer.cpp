// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_UpdateDistanceToPlayer.h"
#include "AIBehaviourTreeGameGameMode.h"
#include "Ball.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIBehaviourTreeGameCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTS_UpdateDistanceToBalls.h"

UBTS_UpdateDistanceToPlayer::UBTS_UpdateDistanceToPlayer()
{
	NodeName = "Update Distance To Player";
}

void UBTS_UpdateDistanceToPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AActor* SelfActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(SelfActorKey.SelectedKeyName));
	AActor* PlayerActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(Player.SelectedKeyName));
	
	if (SelfActor && PlayerActor)
	{

		float Distance = FVector::Dist(SelfActor->GetActorLocation(), PlayerActor->GetActorLocation());
		FVector positionenemys = SelfActor->GetActorLocation();
		FVector positionplayers = PlayerActor->GetActorLocation();

		OwnerComp.GetBlackboardComponent()->SetValueAsFloat(DistanceToPlayer.SelectedKeyName, Distance);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(positionenemy.SelectedKeyName, positionenemys);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(positionplayer.SelectedKeyName, positionplayers);
	}
	AAIController* controller = OwnerComp.GetAIOwner();
	AAIBehaviourTreeGameCharacter* Enemy = Cast<AAIBehaviourTreeGameCharacter>(controller->GetPawn());
	AGameModeBase* GameMode = controller->GetWorld()->GetAuthGameMode();
	AAIBehaviourTreeGameGameMode* AIGameMode = Cast<AAIBehaviourTreeGameGameMode>(GameMode);
	const TArray<ABall*>& BallsList = AIGameMode->GetBalls();
	ABall* NearestBall = nullptr;
	for (int32 i = 0; i < BallsList.Num(); i++)
	{
		if (!BallsList[i]->GetAttachParentActor() &&
			(!NearestBall ||
				FVector::Distance(controller->GetPawn()->GetActorLocation(), BallsList[i]->GetActorLocation()) <
				FVector::Distance(controller->GetPawn()->GetActorLocation(), NearestBall->GetActorLocation())))
		{
			NearestBall = BallsList[i];
		}
	}
	if (NearestBall)
	{
	controller->GetBlackboardComponent()->SetValueAsObject("BestBall", NearestBall);
	}
	else {
		//controller->GetBlackboardComponent()->SetValueAsObject("BestBall", PlayerActor);
	}

	if (NearestBall)
	{
		float Distance = FVector::Dist(Enemy->GetActorLocation(), NearestBall->GetActorLocation());
		FVector PositionNearlestBall = NearestBall->GetActorLocation();
		OwnerComp.GetBlackboardComponent()->SetValueAsFloat(DistanceToBall.SelectedKeyName, Distance);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(PositionBall.SelectedKeyName, PositionNearlestBall);
	}
}
