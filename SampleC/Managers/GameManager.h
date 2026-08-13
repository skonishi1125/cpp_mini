#pragma once

#include <string>
#include "Manager.h"
#include "GameTypes.h"

#include "Modes/FieldMode.h"
#include "Modes/BattleMode.h"
#include "Registries/EntityRegistry.h"

class FieldMode;
class BattleMode;
class EntityRegistry;


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
	FieldMode FieldMode;
	BattleMode BattleMode;

	EntityRegistry Registry;

};