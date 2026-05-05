#include "Slime.h"
#include <iostream>

void Slime::NormalAttack()
{
	std::cout << "スライム は 体当たり した！\n";
}

void Slime::MagicAttack()
{
	Monster::MagicAttack();
	std::cout << "スライム は溶解液 を飛ばした！\n";
}
