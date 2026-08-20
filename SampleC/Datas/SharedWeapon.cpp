#include <string>
#include <memory>

#include "Datas/SharedWeapon.h"
#include "Datas/WeaponData.h"

SharedWeapon::SharedWeapon(std::shared_ptr<WeaponData> InMasterData) : MasterData(InMasterData), CurrentDurability(100), RefineLevel(0)
{
}

int SharedWeapon::GetCalcuratedPower() const
{
	if (!MasterData) return 0;
	return MasterData->GetBasePower() + (RefineLevel * 5);
}

std::string SharedWeapon::GetName() const
{
	if (!MasterData) return "Unknown";
	return MasterData->GetName();
}

void SharedWeapon::EnhanceWeapon()
{
	RefineLevel++;
}
