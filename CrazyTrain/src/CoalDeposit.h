#pragma once
#include "raylib.h"

class CoalDeposit
{
public:
	void Init();
	void Render();

	Rectangle rect;
	std::string spritePath;
};

