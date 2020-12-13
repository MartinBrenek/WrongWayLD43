// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionLib.h"

void UActionLib::Lift(FVector Position, AActor* Target, const FTestDelegate& CallBack)
{
    UTweenContainer* Container = UTweenManagerComponent::CreateTweenContainerStatic();
    UTweenVector* Move = Container->AppendTweenMoveActorTo(Target, Position,5, ETweenEaseType::EaseInCirc);
    //return Move->OnTweenEndDelegate;
}
