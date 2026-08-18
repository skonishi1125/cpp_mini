#pragma once

#include <memory>

// 前方宣言でも namespace が必要
// SModern 名前空間の中にある Entity として宣言。呼ぶときは、SModern::Entity として呼ぶ
namespace SModern
{
	class Entity;
}

namespace SmartModelTest
{
	// 以下のように書くと、SModern:: という表記を省略できるが、.h においてはこれは行わない
	// .h を include した全てのファイルにおいても、この設定が適用されることになり、
	// Entity と書かれたものがどの Entity なのか分からなくなる
	//
	// using namespace SModern;

	std::unique_ptr<SModern::Entity> GenerateModernEntity();
}