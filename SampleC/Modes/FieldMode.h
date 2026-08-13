#pragma once

#include "BaseMode.h"

class FieldMode : public BaseMode
{
public:
	FieldMode() = default;
	~FieldMode() = default;

	EGameState Update() override;

	void Enter() override;
};