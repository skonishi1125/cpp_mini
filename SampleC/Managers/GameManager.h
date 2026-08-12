#pragma once

#include <string>
#include "Manager.h"

class Player;
class Monster;

class GameManager : public Manager<GameManager>
{
	friend class Manager<GameManager>;

public:
	void Initialize();
	Player* SpawnPlayer(const std::string& Name, const int HitPoint);
	Monster* SpawnMonster(const std::string& Name, const int HitPoint);

private:
	GameManager();
	~GameManager();

	Player* MainPlayer;
	Monster* MainMonster;

};