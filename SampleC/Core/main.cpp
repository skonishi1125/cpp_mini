#include <iostream>
#include <string>

#include "Core/Studies/CheckInheritances.h"
#include "Core/Studies/PassFunctions.h"
#include "Core/Studies/CheckVectors.h"
#include "Core/Studies/CheckWeaponPtr.h"

// Managers
#include "Managers/GameManager.h"
#include "Managers/ItemManager.h"

// 各要素
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Monster.h"
#include "Items/Weapon.h"

// 関数系は main() よりも手前に書く

//void AttackSlime()
//{
//    Player Hero("勇者", 100);
//    Player Slime("スライム", 30);
//
//    Weapon Sword("鉄の剣", 15);
//
//    Hero.Attack(Slime);
//    Hero.EquipWeapon(&Sword); // 実体が置かれているメモリアドレスを渡している
//    Hero.Attack(Slime);
//}
//


//
//void InterfaceTest()
//{
//    std::cout << "--- インターフェース動作確認 ---\n";
//
//    Player Hero("勇者", 100);
//    Player Slime("スライム", 30);
//    WoodBox Box;
//
//    std::unique_ptr<Weapon> Sword = std::make_unique<Weapon>("鉄の剣", 15);
//    Hero.EquipWeaponWithSmartPointer(std::move(Sword));
//
//    // Slime, Box 個別のインターフェースを取り出して処理
//    Hero.Attack(Slime);
//    Hero.Attack(Box);
//}
//
//void VirtualTest()
//{
//    std::cout << "--- virtual の実験 ---\n";
//
//    // スライムを生成し親クラスの参照として受け取るケース（Slime を Moster として扱う）
//    //Slime MySlime("スライム", 30);
//    //Monster& TargetMonster = MySlime;
//
//    //TargetMonster.NormalAttack();
//    //TargetMonster.MagicAttack();
//}





int main()
{
    std::cout << "================ Sample C++ ================" << std::endl << std::endl;

    //PassFunctions::TestingHowToPassFunctions();
    //CheckVectors::VectorManagementTest();
    //DisplayWeapon();
    //PlayerEquipWeapon();

    CheckWeaponPtr::UniquePtrTest();


    // 事前の準備
    // GameManager を介して EntityRegistry を用いて Entity をスポーンする
    GameManager::GetInstance().SpawnPlayer("勇者", 50);
    GameManager::GetInstance().SpawnPlayer("魔導士", 50);
    GameManager::GetInstance().SpawnPlayer("弓使い", 50);

    GameManager::GetInstance().SpawnMonster("スライム", 20);
    GameManager::GetInstance().SpawnMonster("モグラ", 20);

    // ゲームループ開始
    GameManager::GetInstance().RunGameLoop();





    std::cout << std::endl << "=================== END ====================" << std::endl;
    return 0;
}
