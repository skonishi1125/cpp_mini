#pragma once

#include <vector>

#include "Managers/GameTypes.h"

class Player;
class Monster;

class BattleMode
{
public:
	BattleMode() = default;
	~BattleMode() = default;

	void StartBattle(const FBattleContext& Context);
	EGameState Update();

private:
	std::vector<Player*> CurrentParty;
	std::vector<Monster*> CurrentEnemies;
};