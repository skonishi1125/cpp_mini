#include "EntityRegistry.h"

#include "Entities/Player.h"
#include "Entities/Monster.h"

EntityRegistry::~EntityRegistry()
{
	for (Entity* TargetEntity : Entities)
	{
		delete TargetEntity;
	}
	Entities.clear();
}

Player* EntityRegistry::SpawnPlayer(const std::string& Name, const int HitPoint)
{
	Player* NewPlayer = new Player(Name, HitPoint);
	Entities.push_back(NewPlayer);
	Party.push_back(NewPlayer);

	return NewPlayer;
}

Monster* EntityRegistry::SpawnMonster(const std::string& Name, const int HitPoint)
{
	Monster* NewMonster = new Monster(Name, HitPoint);
	Entities.push_back(NewMonster);
	ActiveEnemies.push_back(NewMonster);

	return NewMonster;

}