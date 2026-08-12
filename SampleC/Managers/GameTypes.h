#pragma once

#include <vector>

class Player;
class Monster;

enum class EGameState
{
	Field,
	Battle,
	Exit
};

struct FBattleContext
{
	std::vector<Player*> Party;
	std::vector<Monster*> Enemies;
};