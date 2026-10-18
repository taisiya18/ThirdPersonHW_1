#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MyCharacter.generated.h"

// Делегат для события взаимодействия
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);

UCLASS()
class THIRDPERSONHW_1_API AMyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMyCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Действия ввода
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* LookAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* SprintAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* InteractAction;

    // Делегат взаимодействия (подписка в Blueprint)
    UPROPERTY(BlueprintAssignable, Category = "Interaction")
    FOnInteract OnInteract;

    // Флаг спринта (используется в Animation Blueprint)
    UPROPERTY(BlueprintReadOnly, Category = "Movement")
    bool bIsSprinting;

    // Система стамины
    UPROPERTY(BlueprintReadOnly, Category = "Stamina")
    float Stamina;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
    float MaxStamina;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
    float StaminaDrainRate;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina")
    float StaminaRegenRate;

private:
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void StartSprint(const FInputActionValue& Value);
    void StopSprint(const FInputActionValue& Value);
    void Interact(const FInputActionValue& Value);

    float DefaultWalkSpeed;
    float SprintSpeed;
};