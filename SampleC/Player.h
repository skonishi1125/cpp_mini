#pragma once
#include <string>

class Weapon; // 前方宣言

class Player
{
private:
	std::string Name;
	int Hp;

	Weapon* EquippedWeapon;

public:
	Player(std::string InitName, int InitHp);

	void EquipWeapon(Weapon* NewWeapon);

	void Attack(Player& Target);

	void TakeDamage(int Damage);

};