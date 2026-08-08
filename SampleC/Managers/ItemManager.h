#pragma once

#include <string>
#include "Manager.h"

class Weapon;

// Template クラスから継承を行う、CRTP 設計
// 親クラスのテンプレート引数 TManagerType に自分自身の型を渡す
// コンパイル時に ItemManager 専用の親クラスが裏で生成され、
// 各種 子 Manager ごとに独立した static 変数を持てるようになる
class ItemManager : public Manager<ItemManager>
{
	// friend: アクセス権の許可
	// 本クラスのコンストラクタ, デストラクタは private 領域に記載している
	// つまり、親である Manager<ItemManager> でも操作することはできない
	// ただ、親クラスの GetInstance() では "static TManagerType Instance;"としている
	// ↑ 生成処理が走ることになるので、書く処理を行う必要がある
	// friend で、Manager<ItemManager> に対してだけはアクセス許可を出すような形にしている
	friend class Manager<ItemManager>;

public:
	Weapon* SpawnWeapon(const std::string& Name, int Power);

private:
	// シングルトンパターンの子クラスの原則として、外部からの生成を禁止する
	// コンストラクタ / デストラクタを private 配置とすると、
	// ItemManager IM; とか new ItemManager() と書くとコンパイルエラーになる。
	// ※ただし、親である Manager<ItemManager> にだけは別途 friend で許可する形にしている
	ItemManager() = default;
	~ItemManager() = default;

};