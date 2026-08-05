#include <iostream> // std::count などの入出力

#include "Entity.h"

Entity::Entity(const std::string& InitName, int InitHp) : Name(InitName), Hp(InitHp)
{
	std::cout << "Exec Entity() Constructor. Name: " << InitName << " HP: " << InitHp << std::endl;
}

void Entity::TakeDamage(int Damage)
{
	std::cout << "Called Entity::TakeDamage(int Damage)" << std::endl;
}
