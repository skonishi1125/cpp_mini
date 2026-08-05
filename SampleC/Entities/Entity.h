#pragma once

#include <string> // std::string

#include "Core/IDamageable.h"

class Entity : public IDamageable
{
public:
	// string 等の object は & で const 参照渡しで行う（& 無しの値渡しではなく）
	Entity(const std::string& InitName, int InitHp);

	// Interface IDamageable
	void TakeDamage(int Damage) override;

private:
	std::string Name;
	int MaxHp;
	int CurrentHp;
};