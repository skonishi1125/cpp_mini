#include <thread> // std::this_thread::sleep_for用
#include <chrono> // std::chrono::milliseconds用

#include "GameManager.h"
#include "Entities/Player.h"
#include "Entities/Monster.h"

#include "Registries/EntityRegistry.h"

GameManager::GameManager()
{
	DebugManagerName = "GameManager";
}

// Facade パターン
// Entity の生成をカプセル化した Registry を使って行う
// GameManager を使う側 main() などに対して Registry を隠蔽するパターン
void GameManager::SpawnPlayer(const std::string& Name, const int HitPoint)
{
	EntityRegistryObj.SpawnPlayer(Name, HitPoint);
}

void GameManager::SpawnMonster(const std::string& Name, const int HitPoint)
{
	EntityRegistryObj.SpawnMonster(Name, HitPoint);
}

// main() で走らせる処理
// while ループで入力を常に受け付ける Tick のような設定を実現させている
void GameManager::RunGameLoop()
{
	FieldModeObj.Initialize(&EntityRegistryObj);
	BattleModeObj.Initialize(&EntityRegistryObj);

	// ゲーム開始時、Field 状態から始める
	CurrentGameState = EGameState::Field;
	CurrentGameMode = &FieldModeObj; // 値で定義したため、メモリ上に確実に存在しているデータのアドレスを取得する
	CurrentGameMode->Enter(); // nullptr でないことが確定しているため、null チェック不要

	while (CurrentGameState != EGameState::Exit)
	{
		EGameState NextState = CurrentGameMode->Update();

		// 各Mode.Update() で State が返られたときの処理
		if (CurrentGameState != NextState)
		{
			CurrentGameMode->Exit();

			// 戦闘開始
			if (NextState == EGameState::Battle)
			{
				CurrentGameMode = &BattleModeObj;
			}
			else if (NextState == EGameState::Field)
			{
				CurrentGameMode = &FieldModeObj;
			}

			CurrentGameState = NextState;
			CurrentGameMode->Enter();
		}

		// フレームレート制御
		// 16ミリ秒待機させて、60 frame で while がループするようにする
		std::this_thread::sleep_for(std::chrono::milliseconds(16));

	}

}




