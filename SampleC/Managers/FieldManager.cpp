#include <iostream>
#include <conio.h> // 非ブロッキング入力

#include "FieldManager.h"

void FieldManager::Initialize()
{
	std::cout << "\n[FIELD] 探索を開始します...\n";
	std::cout << "（Space : 戦闘へ移動 / Esc : ゲーム終了）\n";
}

// キーボードが押されているかどうかをチェックして、そちらに合った State を返す
EGameState FieldManager::Update()
{
	// key が押されたときに true となる
	if (_kbhit())
	{
		char Key = _getch();
		if (Key == ' ')
		{
			std::cout << "\n敵の気配がする...\n";
			return EGameState::Battle;
		}
		else if (Key == 27)
		{
			std::cout << "\nゲームを終了します。\n";
			return EGameState::Exit;
		}
	}

	// なにも押されなければ、 Field のまま
	return EGameState::Field;

}