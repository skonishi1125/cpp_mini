#pragma once
#include <string>
#include <memory>

class Weapon; // 前方宣言

class Player
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

	void Attack(Player& Target);

	void TakeDamage(int Damage);

};