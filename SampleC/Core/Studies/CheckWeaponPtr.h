#pragma once

class Player;
class Weapon;

namespace CheckWeaponPtr
{
	void DisplayWeapon();
	void PlayerEquipWeapon();
	void EquipWeaponPlayer(Player* TargetPlayer, Weapon* TargetWeapon);
	void UniquePtrTest();
}