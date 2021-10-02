#include <string>
#include <memory>

#include "Train.h"
#include "TrainFurnace.h"
#include "raylib.h"
#include "Program.h"

std::shared_ptr<TrainFurnace> m_furnace;

void Train::Init(std::shared_ptr<TrainFurnace> furnace)
{
	rect = Rectangle {230, Program::GroundHeight - 200, 300, 200};
	speed = 0;
	progress = 0;
	m_furnace = furnace;
}

void Train::Update()
{
	speed = m_furnace->power;
	progress += speed;
}

void Train::Render()
{
	DrawRectangleRec(rect, LIGHTGRAY);
}

void Train::RenderProgress()
{
	//DrawRectangle(0, 0, progress / Program::ScreenWidth, 50, GRAY);
}
