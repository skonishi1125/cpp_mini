#pragma once
#include <string>


class Weapon
{
private:
	std::string Name;
	int AttackPower;

public:
	Weapon(std::string InitName, int InitPower);

	std::string GetName();
	int GetAttackPower();
};