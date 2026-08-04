#include <iostream> // std::count ‚È‚Ç‚Ì“üo—Í

#include "Entity.h"

Entity::Entity(std::string InitName, int InitHp) : Name(InitName), Hp(InitHp)
{
	std::cout << "Exec Entity() Constructor. Name:  " << InitName << " HP: " << InitHp << std::endl;
}
