#pragma once

#include <vector>

#include "BaseMode.h"

class Player;
class Monster;

class BattleMode : public BaseMode
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