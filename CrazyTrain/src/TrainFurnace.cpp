#include <string>
#include <cmath>
#include <iostream>

#include "TrainFurnace.h"
#include "Program.h"

float m_coalBurnTimer;

void TrainFurnace::Init()
{
	rect = Rectangle{ Program::ScreenWidth - 290, Program::GroundHeight - 10, 40, 40 };
	loadedCoal = 0;
	power = 0;
}

void TrainFurnace::LoadCoal(int amount)
{
	loadedCoal += amount;
}

void TrainFurnace::Update()
{
	m_coalBurnTimer += GetFrameTime();

	power += loadedCoal * GetFrameTime();
	if (m_coalBurnTimer > 1.0 && loadedCoal > 0)
	{
		loadedCoal -= 1;
		m_coalBurnTimer = 0;
	}
	if (loadedCoal == 0 && power > 0)
		power -= 10 * GetFrameTime();

	if (power > powerLimit)
	{
		power = 0;
		loadedCoal = 0;
		Program::Defeat();
	}
}

void TrainFurnace::Render()
{
	DrawText(std::to_string(loadedCoal).c_str(), rect.x + 15, rect.y - 30, 18, BLACK);
}

void TrainFurnace::RenderPowerBar()
{
	DrawRectangle(0, Program::ScreenHeight - 18, (power / powerLimit) * Program::ScreenWidth, 15, RED);
}
