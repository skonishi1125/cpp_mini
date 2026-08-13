#include <iostream>
#include <conio.h>

#include "BattleMode.h"

#include "Entities/Player.h"
#include "Entities/Monster.h"

void BattleMode::Enter()
{
    std::cout << "\n------------ [BATTLE] ------------\n";
    std::cout << "戦闘開始！\n";

    if (Registry != nullptr)
    {
        CurrentParty = Registry->GetParty();
        CurrentEnemies = Registry->GetActiveEnemies();
    }

    // C++ では空配列に [0] などでアクセスするとクラッシュするため、チェックする
    // UE5 での .Num() > 0 チェックと同じ。
    if (!CurrentEnemies.empty())
    {
        for (Monster* Enemy : CurrentEnemies)
        {
            std::cout << Enemy->GetName() << "があらわれた！\n";
        }
    }

    std::cout << " (スペースキー: 攻撃 / Rキー: 逃げる)\n";

}

EGameState BattleMode::Update()
{
    if (_kbhit())
    {
        char Key = _getch();

        if (Key == ' ')
        {
            if (!CurrentParty.empty() && !CurrentEnemies.empty())
            {
                for (Player* AttackPlayer : CurrentParty)
                {
                    std::cout << AttackPlayer->GetName() << " の攻撃！\n";
                }
            }
            return EGameState::Field;
        }
        else if (Key == 'r' || Key == 'R')
        {
            std::cout << "[Battle] 無事に逃げ切った！\n";
            return EGameState::Field;
        }
    }

    // 戦闘が継続していれば Battle 状態を維持
    return EGameState::Battle;
}
