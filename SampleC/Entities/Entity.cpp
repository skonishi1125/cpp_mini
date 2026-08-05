#include <iostream> // std::count などの入出力

#include "Entity.h"

Entity::Entity(const std::string& InitName, int InitHp) : Name(InitName), MaxHp(InitHp)
{
	std::cout << "Exec Entity() Constructor. Name: " << InitName << " HP: " << InitHp << std::endl;
	CurrentHp = MaxHp;
}

void Entity::TakeDamage(int Damage)
{
	std::cout << "Called Entity::TakeDamage(int Damage)" << std::endl;
	CurrentHp -= Damage;

	if (CurrentHp < 0) CurrentHp = 0;

}
