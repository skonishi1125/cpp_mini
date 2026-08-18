#include "SmartModelTest.h"
#include "Entities/Modern/Entity.h"

// SModern:: 表記を省略したい場合は、以下のように宣言する
//
// using SModern::Entity;
//
// SModern 名前空間の中にある、全てのクラスや関数を省略できるようにする場合
//
// using namespace SModern;

std::unique_ptr<SModern::Entity> SmartModelTest::GenerateModernEntity()
{
	std::unique_ptr<SModern::Entity> SmartEntity = std::make_unique<SModern::Entity>("ユニークEntity", 50);
	return SmartEntity;
}
