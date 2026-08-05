#include <iostream>
#include "Monster.h"

Monster::Monster(const std::string& InitName, int InitHp) : Entity(InitName, InitHp)
{
	std::cout << "Monster Constructor" << std::endl;
}
//
//Monster::~Monster()
//{
//}
//
//void Monster::TakeDamage(int Damage)
//{
//	Hp -= Damage;
//	std::cout << Name << " は " << Damage << " のダメージを受けた！ (残りHP: " << Hp << ")\n\n";
//}
//
//void Monster::NormalAttack()
//{
//	std::cout << "モンスター の通常攻撃！\n";
//}
//
//void Monster::MagicAttack()
//{
//	std::cout << "モンスター は魔法を発動！\n";
//}
