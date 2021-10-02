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

Texture2D m_smallTrainTex;

Texture2D m_background;
Texture2D m_backgroundFront;

void Train::Init(std::shared_ptr<TrainFurnace> furnace)
{
	rect = Rectangle {250, Program::GroundHeight - 170, 300, 200};
	speed = 0;
	progress = 0;
	m_furnace = furnace;

	m_trainTex = LoadTexture("resources/Train.png");
	if (m_trainWheelTex.size() == 0)
	{
		m_trainWheelTex.emplace_back(LoadTexture("resources/TrainWheel.png"));
		m_trainWheelTex.emplace_back(LoadTexture("resources/TrainWheel2.png"));
		m_trainWheelTex.emplace_back(LoadTexture("resources/TrainWheel3.png"));
	}
	m_smallTrainTex = LoadTexture("resources/SmallTrain.png");

	m_background = LoadTexture("resources/Background.png");
	m_backgroundFront = LoadTexture("resources/BackgroundFront.png");
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
	// Background rendering (bad place to do but this is a gamejam...)
	DrawTexture(m_background, 0, 0, WHITE);

	auto frontPos = -std::fmod(progress * 10, 1.0) * Program::ScreenWidth;
	auto frontPos2 = -std::fmod(progress * 10, 1.0) * Program::ScreenWidth + Program::ScreenWidth;
	DrawTexture(m_backgroundFront, frontPos, 0, WHITE);
	DrawTexture(m_backgroundFront, frontPos2, 0, WHITE);
	

	for (size_t i = 0; i < 8; i++)
	{
		auto xPos = 180 + (i * 110);
		DrawTexture(m_trainWheelTex[(int)m_trainWheelAnimIndex], xPos, rect.y + 170, WHITE);
	}
	DrawTexture(m_trainTex, rect.x - 200, rect.y - 400, WHITE);
}

void Train::RenderProgress()
{
	auto progressPos = (progress / 1.0) * Program::ScreenWidth;
	DrawRectangle(0, 10, progressPos, 30, DARKGREEN);
	DrawTexture(m_smallTrainTex, progressPos - 36, 13, WHITE);
}
