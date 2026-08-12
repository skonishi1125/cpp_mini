#include <thread> // std::this_thread::sleep_for用
#include <chrono> // std::chrono::milliseconds用

#include "GameManager.h"
#include "Entities/Player.h"
#include "Entities/Monster.h"
#include "Managers/FieldManager.h"
#include "Managers/BattleManager.h"

GameManager::GameManager()
{
	DebugManagerName = "GameManager";
}

void GameManager::RunGameLoop()
{
	CurrentState = EGameState::Field;
	FieldMode.Initialize();

	// 無限ループで処理を常に受け付ける設定にする(実質的な Tick 処理)
	while (CurrentState != EGameState::Exit)
	{
		EGameState NextState = CurrentState;

		switch (CurrentState)
		{
		case EGameState::Field:
			NextState = FieldMode.Update();
			break;
		case EGameState::Battle:
			NextState = BattleMode.Update();
			break;
		}

		// 状態が変わったときの処理
		if (CurrentState != NextState)
		{
			// 戦闘開始
			if (NextState == EGameState::Battle)
			{
				FBattleContext Context{
					MainPlayer,
					MainMonster
				};
				BattleMode.StartBattle(Context);
			}

			else if (NextState == EGameState::Field)
			{
				FieldMode.Initialize();
			}

			CurrentState = NextState;
		}

		// フレームレート制御
		// 16ミリ秒待機させて、60 frame で while がループするようにする
		std::this_thread::sleep_for(std::chrono::milliseconds(16));

	}

}

void GameManager::SpawnPlayer(const std::string& Name, const int HitPoint)
{
	MainPlayer = new Player(Name, HitPoint);
}

void GameManager::SpawnMonster(const std::string& Name, const int HitPoint)
{
	MainMonster = new Monster(Name, HitPoint);
}


