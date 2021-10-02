#include <string>
#include <memory>
#include <iostream>

#include "Train.h"
#include "TrainFurnace.h"
#include "raylib.h"
#include "Program.h"

std::shared_ptr<TrainFurnace> m_furnace;

void Train::Init(std::shared_ptr<TrainFurnace> furnace)
{
	rect = Rectangle {250, Program::GroundHeight - 170, 300, 200};
	speed = 0;
	progress = 0;
	m_furnace = furnace;
}

void Train::Update()
{
	speed = m_furnace->power;
	progress += speed * 0.001 * GetFrameTime();

	if (progress >= 1.0)
		Program::Victory();
}

void Train::Render()
{
	DrawRectangleRec(rect, LIGHTGRAY);
}

void Train::RenderProgress()
{
	DrawRectangle(0, 0, (progress / 1.0) * Program::ScreenWidth, 50, GRAY);
}
