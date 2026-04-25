#include <iostream>
#include "Weapon.h"

int main()
{

    Weapon MySword("てつの剣", 15);

    std::cout << "武器名: " << MySword.GetName() << std::endl;
    std::cout << "攻撃力 " << MySword.GetAttackPower() << std::endl;

    return 0;
}