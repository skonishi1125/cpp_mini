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

std::unique_ptr<Weapon> ItemManager::SpawnWeaponWithSP(const std::string& Name, int Power)
{
	// std::make_unique : 安全に std::unique_ptr を生成するための関数
	return std::make_unique<Weapon>(Name, Power);

	// 下記は文法誤り
	// std::unique_ptr<T> のコンストラクタは、引数をそのまま渡すことができない
	// 変数を unique_ptr で作ってから、それを return するのは OK
	//
	// std::unique_ptr<Weapon> MyWeapon = std::make_unique<Weapon>("SmartWeapon", 10);
	// return MyWeapon;
	//
	// もしくは new を使う※ただし、現在では推奨されない
	//
	// return std::unique_ptr<Weapon>(new Weapon(Name, Power));
	//
	// 下記はそもそも文法エラーになる
	//
	// return std::unique_ptr<Weapon>(Name, Power);
}
