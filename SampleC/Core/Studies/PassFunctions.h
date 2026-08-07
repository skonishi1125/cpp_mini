#pragma once

class Player;

// ======================
// 引数の渡し方関連の検証
// ======================
namespace PassFunctions
{
	void FuncByValue(Player p_value);
	void FuncByPointer(Player* p_p);
	void FuncByReference(Player& p_ref);
	void FuncByPointerAndReference(Player*& p_p_and_ref);
	void TestingHowToPassFunctions();
}