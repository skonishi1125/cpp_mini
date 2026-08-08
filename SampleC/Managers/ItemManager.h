#pragma once

#include <string>
#include "Manager.h"

class Weapon;

class ItemManager : public Manager
{
public:
	Weapon* SpawnWeapon(const std::string& Name, int Power);

};