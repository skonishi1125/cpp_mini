#pragma once

#include "Entities/Entity.h"

#include <string>
//#include <memory>

class Player : public Entity
{
public:
	// 子クラスの実装と、親への引数の渡し方
	// 引数を持つコンストラクタを用意して、.cpp 側でパラメータを親に渡すという設計になる
	Player(const std::string& InitName, int InitHp);

	//~Player();

	//void EquipWeapon(Weapon* NewWeapon);

	//void EquipWeaponWithSmartPointer(std::unique_ptr<Weapon> NewWeapon);

	//void Attack(IDamageable& Target);

	//void AttackWithSmartPointer(IDamageable& Target);

	//void TakeDamage(int Damage) override;

private:
	//std::string Name;
	//int Hp;

	//Weapon* EquippedWeapon;
	//std::unique_ptr<Weapon> EquippedWeaponWithSmartPointer;
};