#include <iostream>
#include "Monster.h"

Monster::Monster(const std::string& InitName, int InitHp) : Entity(InitName, InitHp)
{
	std::cout << "Monster Constructor" << std::endl;
}

void Monster::TakeDamage(int Damage)
{
	Entity::TakeDamage(Damage);

	std::cout << Name << " に " << Damage << " のダメージ！ (残りHP: " << CurrentHp << ")\n";

	if (CurrentHp <= 0)
	{
		std::cout << Name << " を " << "たおした！\n";
		// TODO: 経験値処理など
	}
}


//void Monster::NormalAttack()
//{
//	std::cout << "モンスター の通常攻撃！\n";
//}
//
//void Monster::MagicAttack()
//{
//	std::cout << "モンスター は魔法を発動！\n";
//}
