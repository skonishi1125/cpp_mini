#pragma once

#include <string>
#include <memory>

#include "Entity.h"

class Weapon;

namespace SModern
{
	class Player : public SModern::Entity
	{
	public:
		// コンストラクタ: Entity では既に定義済み
		// 定義済みということは、引数無しのデフォルトコンストラクタは自動生成されなくなる
		// そのため、子クラス側では親クラスの初期化に必要な引数をどうするか、コンパイラに明示する必要がある
		// それらを明示するために、子クラス側でもコンストラクタとその引数をどうするかを書く必要がある
		// 親クラスのコンストラクタを完全に使いまわす場合は、using Entity::Entity; と定義してもよい
		// ※using キーワードは文脈によって意味合いが異なり、ここでは親のコンストラクタを持ち込む意味合い
		Player(const std::string& InitName, int InitHp);

		// デストラクタ : Entity で virtual ~Entity() = default; としている
		// C++ において、親クラスに一度 virtual が付与されると、子孫クラスには永遠に virtual として引き継がれる
		// 子クラス側でデストラクタの表記を省略した場合でも、以下の挙動となる
		// * virtual ~Player() が生成される
		// * その中で、自身が持っているスマートポインタを安全に破棄される処理が含まれている
		// * 終わった後、親クラスの ~Entity() を呼び出す
		//
		// ※ virtual を付与しているため仮想関数として扱われるので、override しないといけないのでは？
		// → virtual と = 0 の付属する純粋仮想関数ならばそうだが、C++ における仮想関数は上書きは必須ではない。
		//   そのため、書かない場合、親のデストラクタの default 挙動が呼ばれるという挙動になる
		//
		// ~Player() = default;


		void AttachWeapon(std::unique_ptr<Weapon> NewWeapon);

	private:
		std::unique_ptr<Weapon> EquipWeapon;

	};
}