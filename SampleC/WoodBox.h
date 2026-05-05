#pragma once
#include "IDamageable.h"
#include <iostream>

class WoodBox : public IDamageable
{
private:
    int Durability = 20; // 耐久値

public:
    void TakeDamage(int Damage) override
    {
        Durability -= Damage;
        std::cout << "木箱 に " << Damage << " のダメージが入った！ (残り耐久: " << Durability << ")\n\n";
    }
};