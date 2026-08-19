#include "Player.h"
#include "Items/Weapon.h"

namespace SModern
{
	Player::Player(const std::string& InitName, int InitHp) : Entity(InitName, InitHp)
	{

	}


	void Player::AttachWeapon(std::unique_ptr<Weapon> NewWeapon)
	{
		EquipWeapon = std::move(NewWeapon);
	}


	std::unique_ptr<Weapon> Player::DetachWeapon()
	{
		// std::unique_ptr<Weapon> という返り値の指定だが、nullptr を返している
		// これは unique_ptr に、nullptr 専用の型を受け取れるような設計がされているので問題なく使える
		if (!EquipWeapon) return nullptr;

		return std::move(EquipWeapon);
	}
}