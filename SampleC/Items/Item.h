#pragma once

#include <string>

class Item
{
public:
	Item(const std::string& InitName);
	// Getter の const について
	// * 手前に付与 :「戻り値自体を書き換え禁止の const とする」という明示になる
	// * 後ろに付与 :「この関数はクラスのメンバ変数を書き換えることはない」という宣言。ゲッタはこっち
	std::string GetName() const { return Name; }

protected:
	std::string Name;

};