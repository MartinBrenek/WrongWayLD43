#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "InputCoreTypes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Blackboard.generated.h"

class FBlackboardDecoratorDetails;
class UBehaviorTree;
class UBlackboardComponent;

/**
 * Blackboard special task node.
 * A task node that bases its condition on a Blackboard key.
 */
UCLASS(HideCategories=(Condition),Blueprintable)
class WRONGWAY_API UBTTask_Blackboard : public UBTTask_BlackboardBase
{
	GENERATED_UCLASS_BODY()

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp) const;
	virtual EBlackboardNotificationResult OnBlackboardKeyValueChange(const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID);
	virtual void DescribeRuntimeValues(const UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTDescriptionVerbosity::Type Verbosity, TArray<FString>& Values) const override;
	virtual FString GetStaticDescription() const override;

protected:

	/** value for arithmetic operations */
	UPROPERTY(Category=Blackboard, EditAnywhere, meta=(DisplayName="Key Value"))
	int32 IntValue;

	/** value for arithmetic operations */
	UPROPERTY(Category=Blackboard, EditAnywhere, meta=(DisplayName="Key Value"))
	float FloatValue;

	/** value for string operations */
	UPROPERTY(Category=Blackboard, EditAnywhere, meta=(DisplayName="Key Value"))
	FString StringValue;

	/** cached description */
	UPROPERTY()
	FString CachedDescription;

	/** operation type */
	UPROPERTY()
	uint8 OperationType;

#if WITH_EDITORONLY_DATA

	UPROPERTY(Category=Blackboard, EditAnywhere, meta=(DisplayName="Key Query"))
	TEnumAsByte<EBasicKeyOperation::Type> BasicOperation;

	UPROPERTY(Category=Blackboard, EditAnywhere, meta=(DisplayName="Key Query"))
	TEnumAsByte<EArithmeticKeyOperation::Type> ArithmeticOperation;

	UPROPERTY(Category=Blackboard, EditAnywhere, meta=(DisplayName="Key Query"))
	TEnumAsByte<ETextKeyOperation::Type> TextOperation;

#endif

#if WITH_EDITOR

	/** describe decorator and cache it */
	virtual void BuildDescription();

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;

#endif

	/** take blackboard value and evaluate decorator's condition */
	bool EvaluateOnBlackboard(const UBlackboardComponent& BlackboardComp) const;

	friend FBlackboardDecoratorDetails;
};
