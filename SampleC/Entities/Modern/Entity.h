#pragma once

#include <string>

namespace SModern
{
	class Entity
	{
	public:
		Entity(const std::string& InitName, int InitHp);
		virtual ~Entity() = default;

		// const int GetHp() というように、const を手前に書かない。
		// （手前に書いてしまうと、関数の戻り値そのものを const とするという意味になる）
		// 正しくは、関数内で値を操作しないことを約束させる const（後ろにつける）
		std::string GetName() const { return Name; }
		int GetCurrentHp() const { return CurrentHp; }

	protected:
		std::string Name;
		int MaxHp;
		int CurrentHp;
	};
}
