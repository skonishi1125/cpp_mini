#pragma once

#include <string>
#include "Manager.h"
#include "GameTypes.h"

// 実体で定義しているクラス変数の場合、前方宣言は使えない
// 宣言時点でその Object に対するメモリ確保をする必要があり、そのデータ収集に使うため。
#include "Modes/FieldMode.h"
#include "Modes/BattleMode.h"
#include "Registries/EntityRegistry.h"
//class FieldMode;
//class BattleMode;
//class EntityRegistry;

class BaseGameMode;

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

	FieldMode FieldModeObj;
	BattleMode BattleModeObj;
	EntityRegistry EntityRegistryObj;

	// 現在 Active の State と Active な Mode
	EGameState CurrentGameState;
	BaseGameMode* CurrentGameMode = nullptr;

};