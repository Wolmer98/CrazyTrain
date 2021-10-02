#pragma once
#include "raylib.h"

class TrainFurnace
{
public:
	void Init();
	void LoadCoal(int amount);
	void Update();
	void Render();
	void RenderPowerBar();

	int loadedCoal;
	float power;
	const float powerLimit = 100;
	Rectangle rect;
	std::string spritePath;
};

