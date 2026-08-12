#include <iostream>
#include <conio.h>

#include "BattleManager.h"

#include "Entities/Player.h"
#include "Entities/Monster.h"

void BattleManager::StartBattle(const FBattleContext& Context)
{
	CurrentPlayer = Context.TargetPlayer;
	CurrentMonster = Context.TargetMonster;

	std::cout << "\n[Battle] 戦闘開始！ " << CurrentMonster->GetName() << " があらわれた！\n";
	std::cout << " (スペースキー: 攻撃 / Rキー: 逃げる)\n";
}

EGameState BattleManager::Update()
{
    if (_kbhit())
    {
        char Key = _getch();

        if (Key == ' ')
        {
            std::cout << "\n[Battle] " << CurrentPlayer->GetName() << " の攻撃！\n";
            std::cout << "[Battle] " << CurrentMonster->GetName() << " を倒した！\n";
            return EGameState::Field;
        }
        else if (Key == 'r' || Key == 'R')
        {
            std::cout << "\n[Battle] 無事に逃げ切った！\n";
            return EGameState::Field;
        }
    }

    // 戦闘が継続していれば Battle 状態を維持
    return EGameState::Battle;
}
