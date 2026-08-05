#pragma once

#include "Core/IDamageable.h"

#include <string>
//#include <memory>

class Player : public IDamageable
{
public:
	Player();
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