#pragma once
#include "raylib.h"

class TrainFurnace
{
public:
	void Init();
	void LoadCoal(int amount);
	void Update();
	void Render();

	int loadedCoal;
	float power;
	const float powerLimit = 1000;
	Rectangle rect;
	std::string spritePath;
};

