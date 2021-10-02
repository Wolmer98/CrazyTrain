#pragma once
#include "TrainFurnace.h"

class Train
{
public:
	void Init(std::shared_ptr<TrainFurnace> furnace);
	void Update();
	void Render();
	void RenderProgress();

	Rectangle rect;
	std::string string;

	float speed;
	float progress;
};

