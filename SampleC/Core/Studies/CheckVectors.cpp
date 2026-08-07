#include <vector>
#include <iostream>
#include "CheckVectors.h"

#include "Entities/Player.h"

// std::vector（動的な可変長配列）での、生成キャラクターのメモリ管理の例
void CheckVectors::VectorManagementTest()
{
    std::vector<Player*> PlayerList;

    PlayerList.push_back(new Player("Heap戦士", 100));
    PlayerList.push_back(new Player("Heap弓使い", 60));
    PlayerList.push_back(new Player("Heap魔法使い", 50));
    Player* pPlayerThief = new Player("Heap盗賊", 75);
    PlayerList.push_back(pPlayerThief);

    std::cout << "敵の全体攻撃!\n";

    for (Player* Target : PlayerList)
    {
        if (Target != nullptr)
        {
            Target->TakeDamage(30);
        }
    }

    std::cout << "<処理終了後のメモリ開放処理>\n";
    for (Player* Target : PlayerList)
    {
        delete Target;
        // Target 自体が PlayerList[i] のコピーなので、それに対して nullptr で上書きする必要は無い
        // Target = nullptr;
    }

    // リストの番地ごと全て要素をリセット
    // delete せずに読んでしまうと、ヒープが残りっぱなしになってメモリリークが発生する
    PlayerList.clear();
}
