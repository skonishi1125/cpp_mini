#pragma once

#include <string>

class WeaponData
{
public:
	WeaponData(const std::string& InitName, int InitPower);
	~WeaponData() = default;

	std::string GetName() const { return Name; }
	int GetBasePower() const { return BasePower; }

private:
	std::string Name;
	int BasePower;
};