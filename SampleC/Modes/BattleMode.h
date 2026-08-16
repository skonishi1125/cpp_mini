#pragma once

#include <vector>

#include "BaseGameMode.h"

class Player;
class Monster;

class BattleMode : public BaseGameMode
{
public:
	BattleMode() = default;
	~BattleMode() = default;

	EGameState Update() override;

	void Enter() override;
private:
	std::vector<Player*> CurrentParty;
	std::vector<Monster*> CurrentEnemies;
};