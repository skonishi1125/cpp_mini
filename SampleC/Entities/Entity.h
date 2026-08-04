#pragma once

#include <string> // std::string

class Entity
{
public:
	Entity(std::string InitName, int InitHp);

private:
	std::string Name;
	int Hp;
};