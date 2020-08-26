// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BaseAnimInstance.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnimationEndedCallback, bool, Success);

UCLASS()
class WRONGWAY_API UBaseAnimInstance : public UAnimInstance
{
		GENERATED_BODY()
	
	public:
		UBaseAnimInstance();

		virtual void NativeInitializeAnimation() override;

		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Base Methods")
		void UpdateParameters(FBlackboardKeySelector key);

		UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category = "Base Events")
		FAnimationEndedCallback OnAnimationEnded;
	
	private:
		APawn* BaseOwner;
};