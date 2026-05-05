#pragma once

#include "IDamageable.h"

#include <string>
#include <memory>

class Weapon; // 前方宣言

class Player : public IDamageable // TODO: この public について調べる
{
private:
	std::string Name;
	int Hp;

	Weapon* EquippedWeapon;
	std::unique_ptr<Weapon> EquippedWeaponWithSmartPointer;

public:
	Player(std::string InitName, int InitHp);

	void EquipWeapon(Weapon* NewWeapon);

	void EquipWeaponWithSmartPointer(std::unique_ptr<Weapon> NewWeapon);

	void Attack(IDamageable& Target);

	void TakeDamage(int Damage) override;

};