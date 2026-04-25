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

int main()
{
    DisplayWeapon();

    Player Hero("勇者", 100);
    Player Slime("スライム", 30);

    Weapon Sword("鉄の剣", 15);

    Hero.Attack(Slime);
    Hero.EquipWeapon(&Sword);
    Hero.Attack(Slime);


    return 0;
}
