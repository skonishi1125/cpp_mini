#pragma once

// シングルトンパターンでの設計 親クラス

// テンプレートクラスとしての定義
// template クラス
// * typename T の T は、任意に変えて良い
// * THoge という風に、プレフィックスを付けると UE っぽくなる
// * template クラスとした場合、Manager::GetInstance() というように型を使わない状態では使えない
// *  error C2955: 'Manager': use of class template requires template argument list
template <typename TManagerType>
class Manager
{
public:
	// コピーコンストラクタの禁止
	// ItemManager IM = ItemManager::GetInstance()など、別の変数として生成することを防ぐ
	Manager(const Manager&) = delete;

	// コピー代入演算子の禁止
	// IM = B; というように中身を上書きコピーしたときにコンパイルエラーを出すようにする
	Manager & operator=(const Manager&) = delete;

	// Instance を返す
	// * static でクラスをインスタンス化せずとも呼べる静的関数化する
	// * TManagerType の実体を &(参照) で返す
	static TManagerType& GetInstance()
	{
		static TManagerType Instance;
		return Instance;
	}

protected:
	// default: 特別なことはしないので、標準の処理をしてくれという明示
	// コンストラクタなら標準の生成処理を, デストラクタなら標準の破棄処理をさせる
	Manager() = default;

	// デストラクタに付与する virtual の意図
	// Manager* m = New ItemManager() など、親クラスに子クラスを保持するときをケアした書き方
	// 役割を終えて m = delete; としたとき、virtual がついていないと Manager だけのデストラクタが呼ばれる
	// 結果、ItemManager 側のデストラクタが呼ばれなくなり不具合の原因となり得るため、そちらを対策している
	virtual ~Manager() = default;

};