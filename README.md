# ThirdPersonHW_1

Домашнее задание 1: Расширение Third Person Template (Unreal Engine 5.8)

## Описание

Проект на основе шаблона Third Person. Реализован C++ класс персонажа MyCharacter, унаследованный от ACharacter, с системой Enhanced Input, делегатами, анимациями и механикой выносливости.

## Управление

| Клавиша | Действие |
| --- | --- |
| WASD | Перемещение |
| Mouse | Управление камерой |
| Space | Прыжок |
| Left Shift | Спринт (расходует стамину) |
| E | Взаимодействие |

## Что реализовано

- C++ класс MyCharacter, унаследованный от ACharacter
- Enhanced Input System: Sprint (Left Shift), Interact (E), Jump (Space), Move (WASD), Look (Mouse)
- Dynamic Multicast Delegate (FOnInteract) для события взаимодействия, подписан в Blueprint через Bind Event с выводом Print String "Interaction triggered!"
- Animation Blueprint (ABP_Unarmed) со Sprint-состоянием в State Machine и Transition Rules на основе переменной bIsSprinting
- Система выносливости (Stamina): максимум 100, расход 20/сек при спринте, восстановление 10/сек, принудительная остановка спринта при достижении 0, отображение на экране через AddOnScreenDebugMessage

## Как реализовано

### Класс персонажа (MyCharacter)

Создан C++ класс MyCharacter, наследующий ACharacter. В конструкторе задаются начальные значения: скорость ходьбы (500), скорость спринта (900), максимальная стамина (100), скорость расхода (20/сек) и восстановления (10/сек). Отключено вращение персонажа по контроллеру — вместо этого используется bOrientRotationToMovement, чтобы персонаж поворачивался в сторону движения.

### Система ввода (Enhanced Input)

В BeginPlay загружается Input Mapping Context (IMC_Default) через UEnhancedInputLocalPlayerSubsystem. В SetupPlayerInputComponent привязаны Input Actions: IA_Move, IA_Look, IA_Sprint (Started/Completed), IA_Interact (Started), IA_Jump (Started/Completed). Все действия заданы как UPROPERTY и назначаются в Blueprint.

### Делегат взаимодействия

Объявлен через DECLARE_DYNAMIC_MULTICAST_DELEGATE с UPROPERTY(BlueprintAssignable). При нажатии E вызывается OnInteract.Broadcast(). В EventGraph Blueprint персонажа (BP_ThirdPersonCharacter) на BeginPlay подписан Bind Event to On Interact, который при срабатывании вызывает Print String.

### Система выносливости (Stamina)

Реализована в функции Tick. При спринте стамина уменьшается на StaminaDrainRate * DeltaTime. Когда стамина достигает 0, спринт принудительно прекращается и скорость возвращается к обычной. В покое стамина восстанавливается на StaminaRegenRate * DeltaTime до максимума. Текущее значение отображается на экране.

### Анимации

BP_ThirdPersonCharacter перенаправлен (reparented) на MyCharacter. В Animation Blueprint (ABP_Unarmed) добавлена переменная bIsSprinting, которая обновляется из персонажа. В State Machine добавлено состояние Sprint с переходами: из Idle/Walk в Sprint при bIsSprinting == true, обратно при bIsSprinting == false.

## Структура проекта

- `Source/ThirdPersonHW_1/MyCharacter.h` — заголовочный файл класса персонажа
- `Source/ThirdPersonHW_1/MyCharacter.cpp` — реализация: ввод, движение, спринт, стамина, взаимодействие
- `Content/ThirdPerson/Blueprints/BP_ThirdPersonCharacter` — Blueprint персонажа (reparented на MyCharacter)
- `Content/Characters/Mannequins/Animations/ABP_Unarmed` — Animation Blueprint с State Machine
- `Content/Input/IMC_Default` — Input Mapping Context с привязками клавиш
