#include "Weapon.h"

Weapon::Weapon(std::string InitName, int InitPower) : Name(InitName), AttackPower(InitPower)
{

}

// メンバ初期化子リストとして書かないなら、こんな感じ
//Weapon::Weapon(std::string InitName, int InitPower)
//{
//	Name = InitName;
//	AttackPower = InitPower;
//}

std::string Weapon::GetName()
{
	return Name;
}

int Weapon::GetAttackPower()
{
	return AttackPower;
}
