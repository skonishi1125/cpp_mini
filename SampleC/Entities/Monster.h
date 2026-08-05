#pragma once

#include "Entities/Entity.h"

class Monster : public Entity
{
public:
	Monster(const std::string& InitName, int InitHp);

	void TakeDamage(int Damage) override;

	//void NormalAttack();
	//virtual void MagicAttack();

};