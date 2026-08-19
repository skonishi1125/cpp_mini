#include <iostream>
#include <string>

#include "Core/Studies/CheckInheritances.h"
#include "Core/Studies/PassFunctions.h"
#include "Core/Studies/CheckVectors.h"
#include "Core/Studies/CheckWeaponPtr.h"
#include "Core/Studies/SmartModelTest.h"

// Managers
#include "Managers/GameManager.h"
#include "Managers/ItemManager.h"

// 各要素
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Modern/Player.h"
#include "Entities/Monster.h"
#include "Items/Weapon.h"

// shared_ptr 学習用
#include "Datas/SharedPlayer.h"
#include "Datas/WeaponData.h"

namespace SModern
{
    class Player;
}


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


void GenerateModernAndLegacyClass()
{
    std::unique_ptr<Weapon> SIronSword = ItemManager::GetInstance().SpawnWeaponWithSP("鉄の剣", 15);

    std::unique_ptr<SModern::Player> SModernPlayer = SmartModelTest::GenerateModernPlayer();
    if (SModernPlayer) // std::unique_ptr は、中身が入っていれば true, 入っていなければ false と返してくれる
    {
        std::cout << SModernPlayer->GetName() << std::endl;
        // SModernPlayer->AttachWeapon(SIronSword); は NG
        // 理由は、引数で SIronSeord を指定するとコピーを試みて unique_ptr の規約に引っかかるから
        // std::move を使うことで、SIronSword の所有権を、SModernPlayer.EquipWeapon に委託できる
        SModernPlayer->AttachWeapon(std::move(SIronSword));

        // 装備中の武器ポインタを取得
        const Weapon* CurrentWeapon = SModernPlayer->GetEquippedWeapon();

        // Weapon クラス自体に定義されたゲッタなどから情報を呼ぶ
        if (CurrentWeapon != nullptr)
        {
            std::cout << "装備中の武器: " << CurrentWeapon->GetName() << std::endl;
            std::cout << "攻撃力: " << CurrentWeapon->GetAttackPower() << std::endl;
        }
    }

    Player* LegacyPlayer = SmartModelTest::GenerateLegacyPlayer();
    if (LegacyPlayer != nullptr)
    {
        std::cout << LegacyPlayer->GetName() << std::endl;

        // SIRonSword は、std::move() 済
        // std::move が行われると、中身が自動的に nullptr となっているため、SIronSword を渡しても何も起きない
        LegacyPlayer->AttachWeaponWithSP(std::move(SIronSword));
        std::cout << LegacyPlayer->GetEquippedWeaponWithSPName() << std::endl;

        // 武器のつけ外し
        std::unique_ptr<Weapon> DetachedWeapon;
        if (SModernPlayer)
        {
            DetachedWeapon = SModernPlayer->DetachWeapon();
            if (DetachedWeapon)
            {
                LegacyPlayer->AttachWeaponWithSP(std::move(DetachedWeapon));
            }
        }

        std::cout << LegacyPlayer->GetEquippedWeaponWithSPName() << std::endl;
    }

    delete LegacyPlayer;
    LegacyPlayer = nullptr;
}

void TestSharedPointer()
{
    std::cout << "--- shared_ptr のテスト開始 ---\n";

    std::shared_ptr<WeaponData> SharedIronSwordData = std::make_shared<WeaponData>("鉄の剣マスタデータ", 15);
    std::cout << "参照カウント: " << SharedIronSwordData.use_count() << std::endl; // 1

    {
        SharedPlayer PlayerA("勇者A");
        SharedPlayer PlayerB("勇者B");

        PlayerA.AttachMasterData(SharedIronSwordData);
        PlayerB.AttachMasterData(SharedIronSwordData);

        std::cout << "参照カウント: " << SharedIronSwordData.use_count() << std::endl; // 3

        PlayerA.DetachMasterData();
        std::cout << "参照カウント: " << SharedIronSwordData.use_count() << std::endl; // 2
    } // ブロックスコープにより、PlayerA, PlayerB がメモリから破棄される

    std::cout << "参照カウント: " << SharedIronSwordData.use_count() << std::endl; // 1

} // SharedIronSwordData が消えて、参照カウンタが 0 となる


int main()
{
    std::cout << "================ Sample C++ ================" << std::endl << std::endl;

    //PassFunctions::TestingHowToPassFunctions();
    //CheckVectors::VectorManagementTest();
    //DisplayWeapon();
    //PlayerEquipWeapon();
    //CheckWeaponPtr::UniquePtrTest();

    // スマートポインタ関連
    // GenerateModernAndLegacyClass();
    TestSharedPointer();




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
