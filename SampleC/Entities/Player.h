#pragma once

#include "Entities/Entity.h"

#include <string>
//#include <memory>

class Weapon;

class Player : public Entity
{
public:
	// 子クラスの実装と、親への引数の渡し方
	// 引数を持つコンストラクタを用意して、.cpp 側でパラメータを親に渡すという設計になる
	Player(const std::string& InitName, int InitHp);
	~Player();

	const std::string GetEquippedWeaponName();

	void TakeDamage(int Damage) override;

	void AttachWeapon(Weapon* NewWeapon);


	//~Player();

	//void EquipWeapon(Weapon* NewWeapon);

	//void EquipWeaponWithSmartPointer(std::unique_ptr<Weapon> NewWeapon);

	//void Attack(IDamageable& Target);

	//void AttackWithSmartPointer(IDamageable& Target);


private:
	Weapon* EquippedWeapon;
	//std::unique_ptr<Weapon> EquippedWeaponWithSmartPointer;
};