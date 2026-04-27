#include "Player.h"
#include "Weapon.h"
#include <iostream>

Player::Player(std::string InitName, int InitHp) : Name(InitName), Hp(InitHp)
{

}

// メモリアドレスを受け取り、そちらで処理をする
void Player::EquipWeapon(Weapon* NewWeapon)
{
	EquippedWeapon = NewWeapon; // Weapon* EquippedWeapon と定義しているので、当然メモリアドレスを格納できる
	std::cout << Name << "は [" << EquippedWeapon->GetName() << "] を装備しました。\n";
}

void Player::EquipWeaponWithSmartPointer(std::unique_ptr<Weapon> NewWeapon)
{
	EquippedWeaponWithSmartPointer = std::move(NewWeapon);
	std::cout << Name << "は [" << EquippedWeaponWithSmartPointer->GetName() << "] を装備しました。(with smart pointer) \n";

}

void Player::TakeDamage(int Damage)
{
	Hp -= Damage;
	std::cout << Name << " は " << Damage << " のダメージを受けた！ (残りHP: " << Hp << ")\n\n";

}

// 攻撃対象のメモリアドレスを受け取り、そのアドレスにいる実体のインスタンスに対して処理を行う
void Player::Attack(Player& Target)
{
	std::cout << Name << " の攻撃！\n";

	int BarehandedDamage = 3;
	int TotalDamage = BarehandedDamage;

	if (EquippedWeaponWithSmartPointer != nullptr)
	{
		TotalDamage += EquippedWeaponWithSmartPointer->GetAttackPower();
	}

	Target.TakeDamage(TotalDamage);
}

