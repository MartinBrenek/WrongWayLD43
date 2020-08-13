// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TweenContainer.h"
#include "TweenManagerComponent.h"
#include "TweenVector.h"
#include "ActionLib.generated.h"


/**
 * 
 */

DECLARE_DYNAMIC_DELEGATE(FTestDelegate);

UCLASS()
class WRONGWAY_API UActionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Actions" )
	FOnTweenVectorChange Lift(FVector Position, AActor* Target, const FTestDelegate& Callback);
	
	UPROPERTY(BlueprintReadOnly, Category = "Test")
	FTestDelegate TestCallback;
};
