#include <string>
#include <cmath>
#include <iostream>

#include "TrainFurnace.h"
#include "Program.h"

float m_coalBurnTimer;

void TrainFurnace::Init()
{
	rect = Rectangle{ Program::ScreenWidth - 200, Program::GroundHeight - 10, 20, 20 };
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
		Program::RestartGame();
}

void TrainFurnace::Render()
{
	DrawRectangleRec(rect, GREEN);
}
