#pragma once

#include <string>
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const std::string& InitName, int InitPower);

	int GetAttackPower() const { return AttackPower; }

private:
	int AttackPower;

};