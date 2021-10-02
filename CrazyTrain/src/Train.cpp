#include <string>
#include <memory>
#include <iostream>
#include <vector>

#include "Train.h"
#include "TrainFurnace.h"
#include "raylib.h"
#include "Program.h"

std::shared_ptr<TrainFurnace> m_furnace;
Texture2D m_trainTex;
std::vector<Texture2D> m_trainWheelTex;
float m_trainWheelAnimIndex;

void Train::Init(std::shared_ptr<TrainFurnace> furnace)
{
	rect = Rectangle {250, Program::GroundHeight - 170, 300, 200};
	speed = 0;
	progress = 0;
	m_furnace = furnace;

	m_trainTex = LoadTexture("resources/TrainTex.png");

	if (m_trainWheelTex.size() == 0)
	{
		m_trainWheelTex.emplace_back(LoadTexture("resources/TrainWheel.png"));
		m_trainWheelTex.emplace_back(LoadTexture("resources/TrainWheel2.png"));
		m_trainWheelTex.emplace_back(LoadTexture("resources/TrainWheel3.png"));
	}
}

void Train::Update()
{
	speed = m_furnace->power;
	speed = speed * 0.001 * GetFrameTime();
	progress += speed;

	if (progress >= 1.0)
		Program::Victory();

	m_trainWheelAnimIndex += speed * 1000;
	if (m_trainWheelAnimIndex > m_trainWheelTex.size())
		m_trainWheelAnimIndex = 0;
}

void Train::Render()
{
	DrawTexture(m_trainWheelTex[(int)m_trainWheelAnimIndex], rect.x - 50, rect.y + 150, WHITE);
	DrawRectangleRec(rect, LIGHTGRAY);
}

void Train::RenderProgress()
{
	DrawRectangle(0, 0, (progress / 1.0) * Program::ScreenWidth, 50, GRAY);
}
