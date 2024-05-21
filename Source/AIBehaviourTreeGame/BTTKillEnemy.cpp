// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTKillEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
UBTTKillEnemy::UBTTKillEnemy()
{
	NodeName = "Destroy Owner";
}
EBTNodeResult::Type UBTTKillEnemy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AActor* Enemy = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(SelfActor.SelectedKeyName));
	AActor* PlayerActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(Player.SelectedKeyName));
	TArray<AActor*> AttachedActors;
	PlayerActor->GetAttachedActors(AttachedActors);
	for (AActor* AttachedActor : AttachedActors)
	{
		if (AttachedActor && AttachedActor->ActorHasTag(Tag))
		{
			AttachedActor->Destroy();
			break;
		}
	}
	if (Enemy)
	{
		Enemy->Destroy();
	}
	return EBTNodeResult::Type();
}

