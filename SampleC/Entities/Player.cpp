#include <iostream>

#include "Player.h"
#include "Items/Weapon.h"


Player::Player(const std::string& InitName, int InitHp) : Entity(InitName, InitHp)
{
	//std::cout << "Player Constructor" << std::endl;
}

Player::~Player()
{
	delete EquippedWeapon;
	EquippedWeapon = nullptr;
}

const std::string Player::GetEquippedWeaponName()
{
	if (EquippedWeapon != nullptr)
	{
		return EquippedWeapon->GetName();
	}

	return "なし";
}

void Player::TakeDamage(int Damage)
{
	// Pure C++ には Super:: とか Parent:: とかそういったキーワードは無い
	Entity::TakeDamage(Damage);

	std::cout << Name << " は " << Damage << " のダメージを受けた！ (残りHP: " << CurrentHp << ")\n";

	if (CurrentHp <= 0)
	{
		std::cout << Name << " は " << "死んでしまった！\n";
	}

}

void Player::AttachWeapon(Weapon* NewWeapon)
{
	EquippedWeapon = NewWeapon;
}

//Player::~Player()
//{
//	std::cout << "Playerクラス デストラクタ\n";
//}
//
//// メモリアドレスを受け取り、そちらで処理をする
//void Player::EquipWeapon(Weapon* NewWeapon)
//{
//	EquippedWeapon = NewWeapon; // Weapon* EquippedWeapon と定義しているので、当然メモリアドレスを格納できる
//	std::cout << Name << "は [" << EquippedWeapon->GetName() << "] を装備しました。\n";
//}
//
//void Player::EquipWeaponWithSmartPointer(std::unique_ptr<Weapon> NewWeapon)
//{
//	EquippedWeaponWithSmartPointer = std::move(NewWeapon);
//	std::cout << Name << "は [" << EquippedWeaponWithSmartPointer->GetName() << "] を装備しました。(with smart pointer) \n";
//}
//

//
//// 攻撃対象のメモリアドレスを受け取り、そのアドレスにいる実体のインスタンスに対して処理を行う
//void Player::Attack(IDamageable& Target)
//{
//	std::cout << Name << " の攻撃！\n";
//
//	int BarehandedDamage = 3;
//	int TotalDamage = BarehandedDamage;
//
//	if (EquippedWeapon != nullptr)
//	{
//		TotalDamage += EquippedWeapon->GetAttackPower();
//	}
//
//	// 相手の持つ Interface を呼んで、Player / 敵 / 木箱など に対して個別処理をする
//	Target.TakeDamage(TotalDamage);
//}
//
//void Player::AttackWithSmartPointer(IDamageable& Target)
//{
//	std::cout << Name << " の攻撃！\n";
//
//	int BarehandedDamage = 3;
//	int TotalDamage = BarehandedDamage;
//
//	if (EquippedWeaponWithSmartPointer != nullptr)
//	{
//		TotalDamage += EquippedWeaponWithSmartPointer->GetAttackPower();
//	}
//
//	// 相手の持つ Interface を呼んで、Player / 敵 / 木箱など に対して個別処理をする
//	Target.TakeDamage(TotalDamage);
//}
//

