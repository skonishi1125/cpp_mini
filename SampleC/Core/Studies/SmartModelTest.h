#pragma once

#include <memory>

// Entities/Player クラスの前方宣言
class Player;

// 前方宣言 指定の名前空間 SModern にある Entity や Player を使うと宣言。
// 呼ぶときは、SModern::Entity として呼ぶ
namespace SModern
{
	class Entity;
	class Player;
}

namespace SmartModelTest
{
	// 以下のように書くと、SModern:: という表記を省略できるが、.h においてはこれは行わない
	// .h を include した全てのファイルにおいても、この設定が適用されることになり、
	// Entity と書かれたものがどの Entity なのか分からなくなるため。
	//
	// using namespace SModern;

	std::unique_ptr<SModern::Entity> GenerateModernEntity();
	std::unique_ptr<SModern::Player> GenerateModernPlayer();
	Player* GenerateLegacyPlayer();

}