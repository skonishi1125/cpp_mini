#include <iostream>
#include <conio.h> // 非ブロッキング入力

#include "FieldMode.h"

void FieldMode::Enter()
{
	std::cout << "\n------------ [FIELD] ------------\n";
	std::cout << "探索を開始します...\n";
	std::cout << "（Space : 戦闘へ移動 / Esc : ゲーム終了）\n";
}

// キーボードが押されているかどうかをチェックして、そちらに合った State を返す
EGameState FieldMode::Update()
{
	// key が押されたときに true となる
	if (_kbhit())
	{
		char Key = _getch();
		if (Key == ' ')
		{
			std::cout << "敵の気配がする...\n";
			return EGameState::Battle;
		}
		else if (Key == 27)
		{
			std::cout << "ゲームを終了します。\n";
			return EGameState::Exit;
		}
	}

	// なにも押されなければ、 Field のまま
	return EGameState::Field;

}