#include <iostream>

#include "Bullet.h"
#include "Entities/Modern/Entity.h"

void Bullet::Update()
{
	if (std::shared_ptr<SModern::Entity> LockedTarget = TargetEntity.lock())
	{
		std::cout << "ターゲット生存中..." << std::endl;
	}
	else
	{
		std::cout << "ターゲットがいなくなりました。" << std::endl;
	}
}