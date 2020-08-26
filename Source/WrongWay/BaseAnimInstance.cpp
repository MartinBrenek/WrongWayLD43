// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnimInstance.h"

UBaseAnimInstance::UBaseAnimInstance()
{
    
}

void UBaseAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    // cache the pawn
    BaseOwner = TryGetPawnOwner();
}

void UBaseAnimInstance::UpdateParameters_Implementation(FBlackboardKeySelector key)
{
    
}
