#include <iostream>
#include "Weapon.h"
#include "Player.h"

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
    //delete droppedWeapon; // メモリ開放

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

int main()
{
    while (true)
    {
        MemoryLeakTest();
    }


    //DumplingPointerTest();


    return 0;
}
