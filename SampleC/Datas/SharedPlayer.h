#pragma once

#include <memory>
#include <string>

class WeaponData;
class SharedWeapon;

class SharedPlayer
{
public:
	SharedPlayer(const std::string& InitName);
	~SharedPlayer() = default;

	SharedWeapon* GetEquippedSharedWeapon() const { return EquippedWeapon.get(); }
	std::string GetName() const { return Name; }

	void EquipWeapon(std::unique_ptr<SharedWeapon> NewWeapon);
	void AttachMasterData(std::shared_ptr<WeaponData> Data);
	void DetachMasterData();

private:
	std::string Name;
	std::shared_ptr<WeaponData> EquippedData;
	std::unique_ptr<SharedWeapon> EquippedWeapon;

};