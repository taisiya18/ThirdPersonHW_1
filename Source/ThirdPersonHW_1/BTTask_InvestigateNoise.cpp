#include "BTTask_InvestigateNoise.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_InvestigateNoise::UBTTask_InvestigateNoise()
{
	NodeName = TEXT("Investigate Noise");
	bNotifyTick = true;

	NoiseLocationKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_InvestigateNoise, NoiseLocationKey));
	HeardNoiseKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_InvestigateNoise, HeardNoiseKey));
}

EBTNodeResult::Type UBTTask_InvestigateNoise::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (!AICon || !BB)
	{
		return EBTNodeResult::Failed;
	}

	const FVector NoiseLocation = BB->GetValueAsVector(NoiseLocationKey.SelectedKeyName);
	AICon->MoveToLocation(NoiseLocation, AcceptanceRadius);

	return EBTNodeResult::InProgress;
}

void UBTTask_InvestigateNoise::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon || !AICon->IsFollowingAPath())
	{
		if (UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent())
		{
			BB->SetValueAsBool(HeardNoiseKey.SelectedKeyName, false);
		}
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}