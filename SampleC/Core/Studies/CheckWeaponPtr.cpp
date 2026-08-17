#include <iostream>
//#include <memory>

#include "CheckWeaponPtr.h"

#include "Items/Weapon.h"
#include "Entities/Player.h"
#include "Entities/Monster.h"
#include "Managers/ItemManager.h"

void CheckWeaponPtr::DisplayWeapon()
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


void CheckWeaponPtr::PlayerEquipWeapon()
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

void CheckWeaponPtr::EquipWeaponPlayer(Player* TargetPlayer, Weapon* TargetWeapon)
{
    if (TargetPlayer != nullptr && TargetWeapon != nullptr)
    {
        TargetPlayer->AttachWeapon(TargetWeapon);
    }
}

void CheckWeaponPtr::UniquePtrTest()
{
    std::cout << "--- スマートポインタ ---\n";

    Player Hero("勇者", 100);
    Monster Slime("スライム", 30);

    // スマートポインタを使った形での実装
    // ヒープ に Weapon を作成し、Ownership を Nihontou という変数に持たせる
    // Nihontou が消滅するとき、Weapon も delete される
    std::unique_ptr<Weapon> Nihontou = std::make_unique<Weapon>("日本刀", 10);

    // Weapon* というポインタを受け取る想定の変数であれば、get() でアドレスを渡す
    // ※ std::unique_ptr<Weapon> というスマートポインタで定義されている変数なら、move()で所有権を受け渡すとよい。
    Hero.AttachWeaponWithSP(std::move(Nihontou));
    std::cout << Hero.GetEquippedWeaponWithSPName() << std::endl;

} // 処理終了と同時に Blade は自身の持つメモリを delete で解放