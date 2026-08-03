#include "Monster.h"

#include <iostream>

Monster::Monster(std::string InitName, int InitHp) : Name(InitName), Hp(InitHp)
{
}

Monster::~Monster()
{
}

void Monster::TakeDamage(int Damage)
{
	Hp -= Damage;
	std::cout << Name << " は " << Damage << " のダメージを受けた！ (残りHP: " << Hp << ")\n\n";
}

void Monster::NormalAttack()
{
	std::cout << "モンスター の通常攻撃！\n";
}

void Monster::MagicAttack()
{
	std::cout << "モンスター は魔法を発動！\n";
}
