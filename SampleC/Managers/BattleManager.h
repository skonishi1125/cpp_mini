#pragma once

#include "Manager.h"
#include "GameTypes.h"

class Player;
class Monster;

class BattleManager
{
public:
	BattleManager() = default;
	~BattleManager() = default;

	void StartBattle(const FBattleContext& Context);
	EGameState Update();

private:
	Player* CurrentPlayer = nullptr;
	Monster* CurrentMonster = nullptr;
};