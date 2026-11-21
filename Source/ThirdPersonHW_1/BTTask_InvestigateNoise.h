#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_InvestigateNoise.generated.h"

UCLASS()
class THIRDPERSONHW_1_API UBTTask_InvestigateNoise : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_InvestigateNoise();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector NoiseLocationKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector HeardNoiseKey;

	UPROPERTY(EditAnywhere, Category = "Investigate")
	float AcceptanceRadius = 100.f;
};