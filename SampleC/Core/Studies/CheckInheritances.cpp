#include "CheckInheritances.h"

#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Monster.h"

void CheckInheritances::SetUpEntity()
{
	Entity* pEntity = new Entity("pエンティティ", 25); // heap への定義
	Entity MyEntity("エンティティ", 30); // stack への定義
}

void CheckInheritances::CheckInheritance()
{
    Player MyPlayer("プレイヤー", 100);
    MyPlayer.TakeDamage(20);
    MyPlayer.TakeDamage(79);
    MyPlayer.TakeDamage(5);

    Monster MyMonster("モンスター", 99);
    MyMonster.TakeDamage(30);
    MyMonster.TakeDamage(90);
}
