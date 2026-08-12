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

// main() で走らせる処理
// while ループで入力を常に受け付ける Tick のような設定を実現させている
void GameManager::RunGameLoop()
{
	// ゲーム開始時、Field 状態から始める
	CurrentState = EGameState::Field;
	FieldMode.Initialize();

	while (CurrentState != EGameState::Exit)
	{
		// こちらの State が変わったとき = Field から Battle に遷移など、シーンが変わる瞬間になる
		EGameState NextState = CurrentState;

		switch (CurrentState)
		{
		case EGameState::Field:
			NextState = FieldMode.Update(); // Field 用の入力受付
			break;
		case EGameState::Battle:
			NextState = BattleMode.Update(); // Battle 用の入力受付
			break;
		}

		// 各Mode.Update() で State が返られたときの処理
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


