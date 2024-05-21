// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Logging/LogMacros.h"
#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	SetRootComponent(BallMesh);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyAIController::StaticClass(), FoundActors);
    AActor* Player = GetWorld()->GetFirstPlayerController()->GetPawn();
        if (Player)
        {
            FVector PlayerLocation = Player->GetActorLocation();
            FVector BallLocation = GetActorLocation();
            float Distance = FVector::Dist(PlayerLocation, BallLocation);
            if (Distance < 50&&Distance>10)
            {
             
                this->AttachToActor(Player, FAttachmentTransformRules::KeepRelativeTransform);
                this->SetActorRelativeLocation(FVector(0, 0, 0));
                for (AActor* Actor : FoundActors)
                {
                    AEnemyAIController* EnemyActor = Cast<AEnemyAIController>(Actor);
                    if (EnemyActor)
                    {
                        UBlackboardComponent* BlackboardComp = EnemyActor->GetBlackboardComponent();
                        if (BlackboardComp)
                        {// Imposta la variabile booleana desiderata nella blackboard del nemico
                            BlackboardComp->SetValueAsBool("PlayerHasBall?", true);
                        }
                    }
                }
            }
        }

}

