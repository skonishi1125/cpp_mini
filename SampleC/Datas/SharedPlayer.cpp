#include <iostream>
#include <memory>

#include "SharedPlayer.h"
#include "SharedWeapon.h"
#include "WeaponData.h"

SharedPlayer::SharedPlayer(const std::string& InitName) : Name(InitName)
{

}

void SharedPlayer::EquipWeapon(std::unique_ptr<SharedWeapon> NewWeapon)
{
	EquippedWeapon = std::move(NewWeapon);
	std::cout << Name << " が " << EquippedWeapon->GetName() << "を装備。\n";
}


void SharedPlayer::AttachMasterData(std::shared_ptr<WeaponData> Data)
{
	EquippedData = Data;
	std::cout << Name << " が " << EquippedData->GetName() << " のデータを読み込みました。\n";
}

void SharedPlayer::DetachMasterData()
{
	if (EquippedData)
	{
		std::cout << Name << "がデータを手放しました。\n";
		EquippedData.reset(); // 中身を nullptr にする
	}
}
