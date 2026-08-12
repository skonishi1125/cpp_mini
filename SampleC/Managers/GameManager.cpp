#include "GameManager.h"
#include "Entities/Player.h"
#include "Entities/Monster.h"

GameManager::GameManager()
{
	DebugManagerName = "GameManager";
}

GameManager::~GameManager()
{
	delete MainPlayer;
	MainPlayer = nullptr;

	delete MainMonster;
	MainMonster = nullptr;
}

void GameManager::Initialize()
{

}

Player* GameManager::SpawnPlayer(const std::string& Name, const int HitPoint)
{
	MainPlayer = new Player(Name, HitPoint);
	return MainPlayer;
}

Monster* GameManager::SpawnMonster(const std::string& Name, const int HitPoint)
{
	MainMonster = new Monster(Name, HitPoint);
	return MainMonster;
}


