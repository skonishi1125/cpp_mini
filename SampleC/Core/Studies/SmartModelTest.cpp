#include "SmartModelTest.h"
#include "Entities/Modern/Entity.h"
#include "Entities/Modern/Player.h"

// SModern:: 表記を省略したい場合は、以下のように宣言する
//
// using SModern::Entity;
//
// SModern 名前空間の中にある、全てのクラスや関数を省略できるようにする場合
//
// using namespace SModern;

std::unique_ptr<SModern::Entity> SmartModelTest::GenerateModernEntity()
{
	std::unique_ptr<SModern::Entity> SmartEntity = std::make_unique<SModern::Entity>("uniqueEntity", 50);
	return SmartEntity;
}

std::unique_ptr<SModern::Player> SmartModelTest::GenerateModernPlayer()
{
	std::unique_ptr<SModern::Player> SmartPlayer = std::make_unique<SModern::Player>("uniquePlayer", 80);
	return SmartPlayer;
}
