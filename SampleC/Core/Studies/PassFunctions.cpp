#include <iostream>

#include "PassFunctions.h"
#include "Entities/Player.h"

void PassFunctions::FuncByValue(Player p_value)
{
    std::cout << p_value.GetName() << std::endl;
}

void PassFunctions::FuncByPointer(Player* p_p)
{
    std::cout << p_p->GetName() << std::endl;
}

void PassFunctions::FuncByReference(Player& p_ref)
{
    std::cout << p_ref.GetName() << std::endl;
}

void PassFunctions::FuncByPointerAndReference(Player*& p_p_and_ref)
{
    std::cout << p_p_and_ref->GetName() << std::endl;
}

void PassFunctions::TestingHowToPassFunctions()
{
    // 値渡し
    Player MyPlayer_Value = Player("値渡し", 100);
    FuncByValue(MyPlayer_Value);

    // ポインタ渡し
    Player MyPlayer_Pointer = Player("ポインタ渡し", 100); // データそのもの
    Player* PointerPlayer = &MyPlayer_Pointer; // 作ったデータのアドレスを & で参照してポインタへ格納
    Player** DoublePointerPlayer = &PointerPlayer; // ↑で作ったポインタのアドレスを & で参照してダブルポインタへ格納
    FuncByPointer(PointerPlayer);
    FuncByPointer(*DoublePointerPlayer); // ダブルポインタは、* を付与して実体へのポインタを呼べる（デリファレンス）

    // 参照渡し
    Player MyPlayer_Reference = Player("参照渡し", 200);
    FuncByReference(MyPlayer_Reference);

    // ポインタ参照渡し
    Player* MyPlayer_Pointer_2 = new Player("ポインタPlayer", 99);
    FuncByPointerAndReference(MyPlayer_Pointer_2);
    delete MyPlayer_Pointer_2;
    MyPlayer_Pointer_2 = nullptr;
}

