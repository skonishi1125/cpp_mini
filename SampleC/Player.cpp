#include "Player.h"
#include "Weapon.h"
#include <iostream>

Player::Player(std::string InitName, int InitHp) : Name(InitName), Hp(InitHp)
{

}

void Player::EquipWeapon(Weapon* NewWeapon)
{
	EquippedWeapon = NewWeapon;
	std::cout << Name << "は [" << EquippedWeapon->GetName() << "] を装備しました。\n";
}

void Player::TakeDamage(int Damage)
{
	Hp -= Damage;
	std::cout << Name << " は " << Damage << " のダメージを受けた！ (残りHP: " << Hp << ")\n\n";

}

void Player::Attack(Player& Target)
{
	std::cout << Name << " の攻撃！\n";

	int BarehandedDamage = 3;
	int TotalDamage = BarehandedDamage;

	if (EquippedWeapon != nullptr)
	{
		TotalDamage += EquippedWeapon->GetAttackPower();
	}

	Target.TakeDamage(TotalDamage);
}

