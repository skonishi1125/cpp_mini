#pragma once

#include "Entities/Entity.h"

//#include <string> // std::string

class Monster : public Entity
{
public:
	Monster(const std::string& InitName, int InitHp);

	//void TakeDamage(int Damage);

	//void NormalAttack();
	//virtual void MagicAttack();

//private:
//	std::string Name;
//	int Hp;
};