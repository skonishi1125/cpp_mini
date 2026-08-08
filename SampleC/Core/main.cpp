#include <iostream>
//#include <memory>

#include "Core/Studies/CheckInheritances.h"
#include "Core/Studies/PassFunctions.h"
#include "Core/Studies/CheckVectors.h"

// Managers
#include "Managers/Manager.h"
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
//void MemoryLeakTest()
//{
//    // ヒープ領域に動的確保して、Weapon を作成
//    // delete を付与していないため、タスクマネージャーから SampleC.exe を開くとメモリが溜まっていくことが分かる
//    while (true)
//    {
//        Weapon* droppedWeapon = new Weapon("呪われた剣", 50);
//        std::cout << droppedWeapon->GetName() << " を手に入れた！\n";
//    }
//
//    //Weapon* droppedWeapon = new Weapon("呪われた剣", 50);
//    //std::cout << droppedWeapon->GetName() << " を手に入れた！\n";
//    //delete droppedWeapon; // メモリ開放処理
//
//}
//
//
//void DumglingPointerTest()
//{
//    std::cout << "--- ダングリングポインタ実験 開始 ---\n";
//
//    Player Hero("勇者", 100);
//    Player Slime("スライム", 30);
//
//    Weapon* MagicSword = new Weapon("魔法剣", 30);
//    Hero.EquipWeapon(MagicSword);
//
//    std::cout << "--- 武器ポインタのメモリを開放 ---\n";
//    delete MagicSword; // 武器をdeleteして、格納先のメモリを解放
//
//    Hero.Attack(Slime); // 勇者の装備している剣のアドレスは解放されているが、そちらで攻撃を試みる
//}
//
//void SmartPointerTest()
//{
//    std::cout << "--- スマートポインタ ---\n";
//
//    Player Hero("勇者", 100);
//    Player Slime("スライム", 30);
//
//    // スマートポインタを使った形での実装
//    // ヒープ に Weapon を作成し、Ownership を Blade という変数に持たせる
//    // Blade が消滅するとき、Weapon も delete される
//    std::unique_ptr<Weapon> Blade = std::make_unique<Weapon>("日本刀", 10);
//
//    // Weapon* というポインタを受け取る想定の変数であれば、get() でアドレスを渡す
//    // ※ std::unique_ptr<Weapon> というスマートポインタで定義されている変数なら、move()で所有権を受け渡すとよい。
//    Hero.EquipWeaponWithSmartPointer(std::move(Blade));
//    Hero.Attack(Slime);
//
//    // 処理終了と同時に Blade は自身の持つメモリを delete で解放
//}
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



void DisplayWeapon()
{
    // こういった関数内に一時的に用意するオブジェクトは、ポインタを使うべきでない
    // 作成後、すぐ std::cout で表示するケースがあったとして、ポインタなので nullptr チェックが必要
    // ただし生成後すぐ使うようなケースは nullptr でないことは自明。
    // つまり、nullptr チェックが不要 = ポインタを使うべき場面ではない。
    // Weapon* IronSword = new Weapon("鉄の剣", 20);

    Weapon IronSword("どうの剣", 25);
    std::cout << "武器名: " << IronSword.GetName() << std::endl;
    std::cout << "攻撃力 " << IronSword.GetAttackPower() << std::endl;
}


void PlayerEquipWeapon()
{
    Player Hero("勇者", 100);
    Weapon* DroppedWeapon = ItemManager::GetInstance().SpawnWeapon("鉄の剣", 10);

    std::cout << ItemManager::GetInstance().GetDebugManagerName() << std::endl;

    std::cout << Hero.GetEquippedWeaponName() << std::endl;
    Hero.AttachWeapon(DroppedWeapon);
    std::cout << Hero.GetEquippedWeaponName() << std::endl;

    delete DroppedWeapon;
    DroppedWeapon = nullptr;
}

int main()
{
    std::cout << "================ Sample C++ ================" << std::endl << std::endl;

    //PassFunctions::TestingHowToPassFunctions();
    //CheckVectors::VectorManagementTest();

    //DisplayWeapon();
    PlayerEquipWeapon();

    std::cout << std::endl << "=================== END ====================" << std::endl;
    return 0;
}
