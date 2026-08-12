#pragma once

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
	Player* TargetPlayer;
	Monster* TargetMonster;
};