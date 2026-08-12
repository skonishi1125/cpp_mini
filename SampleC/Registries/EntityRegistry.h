#pragma once

#include <string>
#include <vector>

class Entity;
class Player;
class Monster;

class EntityRegistry
{
public:
	EntityRegistry() = default;
	~EntityRegistry();

	Player* SpawnPlayer(const std::string& Name, const int HitPoint);
	Monster* SpawnMonster(const std::string& Name, const int HitPoint);

	const std::vector<Player*> GetParty() const { return Party; }
	const std::vector<Monster*> GetActiveEnemies() const { return ActiveEnemies; }


private:
	// メモリ管理用の、生成したすべての Entity を持つ配列
	std::vector<Entity*> Entities;

	std::vector<Player*> Party;

	std::vector<Monster*> ActiveEnemies;

};