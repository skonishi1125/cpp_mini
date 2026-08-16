#pragma once

#include "BaseGameMode.h"

class FieldMode : public BaseGameMode
{
public:
	FieldMode() = default;
	~FieldMode() = default;

	EGameState Update() override;

	void Enter() override;
};