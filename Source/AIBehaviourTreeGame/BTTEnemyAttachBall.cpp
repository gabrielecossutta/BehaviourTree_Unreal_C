// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTEnemyAttachBall.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIBehaviourTreeGameCharacter.h"
#include "AIController.h"
#include "Engine/GameInstance.h"
#include <Kismet/GameplayStatics.h>

EBTNodeResult::Type UBTTEnemyAttachBall::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UWorld* World = UGameplayStatics::GetGameInstance(GetWorld())->GetWorld();

	if (World)
	{
		FString CurrentLevelName = World->GetMapName();

		UGameplayStatics::OpenLevel(World, *CurrentLevelName);
	}

	if (World)
	{
		FString CurrentLevelName = World->GetMapName();

		UGameplayStatics::OpenLevel(World, *CurrentLevelName);
	}

	return EBTNodeResult::Type();

}
