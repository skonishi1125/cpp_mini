#include <iostream>
//#include <memory>
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Monster.h"

// 関数系は main() よりも手前に書かなければ認識されない
//void DisplayWeapon()
//{
//    Weapon MySword("鉄の剣", 15);
//
//    std::cout << "武器名: " << MySword.GetName() << std::endl;
//    std::cout << "攻撃力 " << MySword.GetAttackPower() << "\n" << std::endl;
//}
//
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

void SetUpEntity()
{
    Entity* pEntity = new Entity("pエンティティ", 25); // heap への定義
    Entity MyEntity("エンティティ", 30); // stack への定義
}

void CheckInheritance()
{
    Player MyPlayer("プレイヤー", 100);
    MyPlayer.TakeDamage(20);
    MyPlayer.TakeDamage(79);
    MyPlayer.TakeDamage(5);

    Monster MyMonster("モンスター", 99);
    MyMonster.TakeDamage(30);
    MyMonster.TakeDamage(90);
}

// スタックに Player を生成して、そのオブジェクトを返す
// スタックは } の後すぐに破棄されることになるので、
// 呼び出し元のスタック領域に強引にコピーして、元となった実体を破棄するような挙動になる
// また、別のケースで Entity 型で Player を返す際に値渡しとした場合、
// 子クラスのデータがそぎ落とされて親クラスの部分だけがコピーされる現象が起きるケースもある （Object Slicing）
//
// そのため、Object はポインタを使ってアドレスで受け渡すのが基本。この関数は好ましくない
Player GenerateHeroOnStack()
{
    Player StackPlayer("スタック", 100);
    return StackPlayer;
}

// ヒープに Player を生成して、そのアドレスを返す
Player* GenerateHeroOnHeap()
{
    Player* pNewPlayer = new Player("ヒープ", 100);
    return pNewPlayer;
}

// PHP などでは関数にオブジェクトを渡すと、暗黙的に参照を渡してくれる
// C++ に関しては、* や & を付与せず渡すと、全く新しいコピーを渡すというルールが働く
// そのため、この関数では元の TargetPlayer(StackHero) のコピーを処理することになる
// ダメージを減らす処理をしているが、
// * 無傷のオリジナルからコピーを作って
// * コピーの体力を減らす
// という処理になり、元のオリジナルの体力を減らしたりすることができない。
void ProcessBattleUsingStack(Player TargetPlayer)
{
    std::cout << "--- 戦闘開始 ---\n";
    TargetPlayer.TakeDamage(20);
}

void ProcessBattleUsingHeap(Player* TargetPlayer)
{
    if (TargetPlayer != nullptr)
    {
        std::cout << "-- 戦闘開始 ---\n";
        TargetPlayer->TakeDamage(20);
    }
}

int main()
{
    std::cout << "================ Sample C++ ================" << std::endl << std::endl;
    std::cout << "Completed Orgamize folders!" << std::endl;

    // SetUpEntity();
    //CheckInheritance();

    Player StackHero = GenerateHeroOnStack();
    ProcessBattleUsingStack(StackHero);
    ProcessBattleUsingStack(StackHero);

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


    Player* HeapHero = GenerateHeroOnHeap();
    ProcessBattleUsingHeap(HeapHero);
    ProcessBattleUsingHeap(HeapHero);
    delete HeapHero;
    HeapHero = nullptr;



    std::cout << std::endl << "=================== END ====================" << std::endl;
    return 0;
}
