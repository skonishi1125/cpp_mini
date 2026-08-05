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

protected:
	// Name は xx のダメージ というようにログを出したい場合は、子クラスで参照できるように調整する必要がある
	// そういったものは protected で適宜管理する。
	// イメージとしては、private に書いて不都合があれば protected に移行していく感じ
	std::string Name;
	int CurrentHp;
	int MaxHp;

private:
};