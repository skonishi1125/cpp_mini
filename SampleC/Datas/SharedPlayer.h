#pragma once

#include <memory>
#include <string>

class WeaponData;

class SharedPlayer
{
public:
	SharedPlayer(const std::string& InitName);
	~SharedPlayer() = default;

	void AttachMasterData(std::shared_ptr<WeaponData> Data);
	void DetachMasterData();

private:
	std::string Name;
	std::shared_ptr<WeaponData> EquippedData;

};