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

## Реализовано

- C++ класс MyCharacter, унаследованный от ACharacter
- Enhanced Input System: Sprint (Left Shift) и Interact (E)
- Dynamic Multicast Delegate для события взаимодействия
- Animation Blueprint со Sprint-состоянием в State Machine
- Система выносливости (Stamina): расход при спринте, восстановление, отображение на экране
