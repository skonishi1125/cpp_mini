#pragma once

#include "Managers/GameTypes.h"

class BaseMode
{
public:
	// C++ ポリモーフィズムを考慮するクラスには、 virtual デストラクタを明記する
	// 親クラスのポインタ経由で子クラスが delete されたとき、子クラスのデストラクタが呼ばれないことを防ぐ
	// * BaseMode* ModeObj という定義があり、その中に FieldMode のクラスオブジェクトが入っていたとする
	// * delete ModeObj としたとき、明記が無いと子クラスのデストラクタが呼ばれずメモリリークの要因となる
	virtual ~BaseMode() = default;

	// 子クラスで実装必須な関数は、仮想関数としておく
	virtual EGameState Update() = 0;

	// 子クラスで任意実装である関数は、空の実装にしておき、必要なら override させる
	virtual void Enter() {};
	virtual void Exit() {};
};