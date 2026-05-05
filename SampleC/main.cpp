#include <iostream>
#include <memory>
#include "Weapon.h"
#include "Player.h"
#include "WoodBox.h"

// 関数系は main() よりも手前に書かなければ認識されない
void DisplayWeapon()
{
    Weapon MySword("鉄の剣", 15);

    std::cout << "武器名: " << MySword.GetName() << std::endl;
    std::cout << "攻撃力 " << MySword.GetAttackPower() << "\n" << std::endl;
}

void AttackSlime()
{
    Player Hero("勇者", 100);
    Player Slime("スライム", 30);

    Weapon Sword("鉄の剣", 15);

    Hero.Attack(Slime);
    Hero.EquipWeapon(&Sword); // 実体が置かれているメモリアドレスを渡している
    Hero.Attack(Slime);
}

void MemoryLeakTest()
{
    // ヒープ領域に動的確保して、Weapon を作成
    Weapon* droppedWeapon = new Weapon("呪われた剣", 50);
    std::cout << droppedWeapon->GetName() << " を手に入れた！\n";
    //delete droppedWeapon; // メモリ開放処理

}

void DumplingPointerTest()
{
    std::cout << "--- ダングリングポインタ実験 開始 ---\n";

    Player Hero("勇者", 100);
    Player Slime("スライム", 30);

    Weapon* MagicSword = new Weapon("魔法剣", 30);
    Hero.EquipWeapon(MagicSword);

    delete MagicSword; // 武器をdeleteして、格納先のメモリを解放

    Hero.Attack(Slime); // 勇者の装備している剣のアドレスは解放されているが、そちらで攻撃を試みる
}

void SmartPointerTest()
{
    std::cout << "--- スマートポインタ ---\n";

    Player Hero("勇者", 100);
    Player Slime("スライム", 30);

    // スマートポインタを使った形での実装
    // ヒープ に Weapon を作成し、Ownership を Blade という変数に持たせる
    // Blade が消滅するとき、Weapon も delete される
    std::unique_ptr<Weapon> Blade = std::make_unique<Weapon>("日本刀", 10);

    // Weapon* というポインタを受け取る想定の変数であれば、get() でアドレスを渡す
    // ※ std::unique_ptr<Weapon> というスマートポインタで定義されている変数なら、move()で所有権を受け渡すとよい。
    Hero.EquipWeaponWithSmartPointer(std::move(Blade));
    Hero.Attack(Slime);

    // 処理終了と同時に Blade は自身の持つメモリを delete で解放
}

void InterfaceTest()
{
    std::cout << "--- インターフェース動作確認 ---\n";

    Player Hero("勇者", 100);
    Player Slime("スライム", 30);
    WoodBox Box;

    std::unique_ptr<Weapon> Sword = std::make_unique<Weapon>("鉄の剣", 15);
    Hero.EquipWeaponWithSmartPointer(std::move(Sword));

    // Slime, Box 個別のインターフェースを取り出して処理
    Hero.Attack(Slime);
    Hero.Attack(Box);
}

int main()
{
    InterfaceTest();
    return 0;
}
