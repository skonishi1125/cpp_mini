#pragma once

#include <memory>

namespace SModern
{
	class Entity;
}

class Bullet
{
public:
	void SetTarget(std::shared_ptr<SModern::Entity> Target) { TargetEntity = Target; }
	void Update();

private:
	std::weak_ptr<SModern::Entity> TargetEntity;
};