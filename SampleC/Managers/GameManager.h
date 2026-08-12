#pragma once

#include <string>
#include "Manager.h"
#include "GameTypes.h"

#include "FieldManager.h"
#include "BattleManager.h"

class FieldManager;
class BattleManager;

class GameManager : public Manager<GameManager>
{
	friend class Manager<GameManager>;

public:
	void Initialize();
	void RunGameLoop();

	void SpawnPlayer(const std::string& Name, const int HitPoint);
	void SpawnMonster(const std::string& Name, const int HitPoint);

private:
	GameManager();
	~GameManager() = default;

	EGameState CurrentState;
	FieldManager FieldMode;
	BattleManager BattleMode;

	Player* MainPlayer;
	Monster* MainMonster;

};