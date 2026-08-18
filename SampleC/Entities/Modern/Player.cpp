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
}