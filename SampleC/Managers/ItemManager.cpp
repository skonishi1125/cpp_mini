#include <string>

#include "ItemManager.h"
#include "Items/Weapon.h"

// コンストラクタでメンバ初期化子リストを使うのはベストプラクティスだが、
// 親クラスで定義されたメンバ変数は、初期化子リストで定義することはできない
// * ItemManager::ItemManager() : DebugManagerName("ItemManager");
// * error C2614: 'ItemManager': illegal member initialization: 'DebugManagerName' is not a base or member
// なので、親クラスのデータをコンストラクタで調整する場合は普通の関数内に書く形にする
ItemManager::ItemManager()
{
	DebugManagerName = "ItemManager";
}

// Heap に Weapon データを用意して、それを格納したポインタを返す
Weapon* ItemManager::SpawnWeapon(const std::string& Name, int Power)
{
	return new Weapon(Name, Power);
}
