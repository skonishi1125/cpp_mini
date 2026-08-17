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
    // スマートポインタ unique_ptr を Player クラスに導入したことで、
    // FuncByValue(MyPlayer_Value) などがスマートポインタの制約に引っかかり、
    // インスタンスのコピーを作成して関数へと渡すことができなくなった。
    // 値渡し 部分
    // * Player MyPlayer_Value = Player("値渡し", 100);
    // * "=" を使用している実装自体が、コピー初期化と呼ばれるもの
    // * 一時的な Player Object を MyPlayer_Value に入れているという挙動なのでそちらでエラーになる
    // ポインタ渡し 部分
    // * 同じくコピー初期化部分でエラーに引っかかる。
    // * 一時的な Object なら、所有権の移動が自動で行われる挙動もあるが、今回 Player で デストラクタを自身で定義している
    // * 開発者がデストラクタを自分で定義している場合、ムーブコンストラクタは自動で生成されない
    // #if 0 - #endif : プリプロセッサ（コンパイル前のコード処理）単位でのコードのコメントアウト
    // #if 1 とするだけで中身のコードを最有効化できるので、/* */ などと併用できる
#if 0
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
#endif
    Player MyPlayer_Value_2("値", 100); // 一時的な Object を作らないケースでの定義（これなら通る）
    //FuncByValue(MyPlayer_Value_2); // こちらでコピーが発生するので、unique_ptr に引っかかる

    Player* MyPlayer_Ptr_2 = new Player("ポインタ", 100);
    FuncByPointer(MyPlayer_Ptr_2); // メモリアドレスだけのコピーなら OK

    Player MyPlayer_Ref_2("参照", 20); // 一時的な Object を作らないケースでの定義 OK
    FuncByReference(MyPlayer_Ref_2); // 参照はコピーが発生しないので OK

    Player* MyPlayer_Ptr_3 = new Player("ポインタ参照", 99);
    FuncByPointerAndReference(MyPlayer_Ptr_3);// メモリアドレス自体の参照も OK


}

