#pragma once

#include <vector>

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
	std::vector<Player*> CurrentParty;
	std::vector<Monster*> CurrentEnemies;
};