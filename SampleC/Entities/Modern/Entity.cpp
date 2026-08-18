#include "Entity.h"

// SModern::Entity::Hoge() と、SModern:: を記述する手間を減らすために namespace でくくる
namespace SModern
{
	Entity::Entity(const std::string& InitName, int InitHp) : Name(InitName), MaxHp(InitHp)
	{
		CurrentHp = MaxHp;
	}
}
