#pragma once

#include <memory>
#include <string>

class WeaponData;

class SharedWeapon
{
public:
	SharedWeapon(std::shared_ptr<WeaponData> InMasterData);
	~SharedWeapon() = default;

	int GetCalcuratedPower() const;
	std::string GetName() const;

	void EnhanceWeapon();

private:
	std::shared_ptr<WeaponData> MasterData;
	int CurrentDurability;
	int RefineLevel;
};