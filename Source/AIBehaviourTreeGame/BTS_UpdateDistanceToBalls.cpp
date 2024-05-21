// Fill out your copyright notice in the Description page of Project Settings.

#include "AIBehaviourTreeGameGameMode.h"
#include "Ball.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIBehaviourTreeGameCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTS_UpdateDistanceToBalls.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

UBTS_UpdateDistanceToBalls::UBTS_UpdateDistanceToBalls()
{
	NodeName = "CheckPlayerHasBall";
}

void UBTS_UpdateDistanceToBalls::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    AActor* SelfActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(SelfActorKey.SelectedKeyName));
    AActor* PlayerActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(Player.SelectedKeyName));

        if (PlayerActor)
        {
            bool bActorFound = false;

            // Iterate over attached actors
            TArray<AActor*> AttachedActors;
            PlayerActor->GetAttachedActors(AttachedActors);
            for (AActor* AttachedActor : AttachedActors)
            {
                if (AttachedActor && AttachedActor->ActorHasTag(Tag))
                {
                    bActorFound = true;
                    break;
                }
            }
            if (bActorFound)
            {
                OwnerComp.GetBlackboardComponent()->SetValueAsBool(PlayerHasBall.SelectedKeyName, true);
            }
            else
            {
                OwnerComp.GetBlackboardComponent()->SetValueAsBool(PlayerHasBall.SelectedKeyName, false);
            }
        }
  






 /*   if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
    {
        if (AActor* PlayerActor = PlayerController->GetPawn())
        {
            if (PlayerActor->GetDefaultSubobjectByName(ChildComponentName))
            {
            }
            else
            {
                OwnerComp.GetBlackboardComponent()->SetValueAsBool(PlayerHasBall.SelectedKeyName, false);
            }
        }
    }*/
}
