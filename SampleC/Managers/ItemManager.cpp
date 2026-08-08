#include "ItemManager.h"
#include "Items/Weapon.h"

// Heap に Weapon データを用意して、それを格納したポインタを返す
Weapon* ItemManager::SpawnWeapon(const std::string& Name, int Power)
{
	return new Weapon(Name, Power);
}
