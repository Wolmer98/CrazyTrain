#include <string>

#include "Player.h"
#include "raylib.h"
#include "raymath.h"
#include "Program.h"

Texture2D m_playerTex;
Texture2D m_playerTexFlipped;
Texture2D m_playerCoalTex;
Texture2D m_playerCoalTexFlipped;
int m_lastDirection;

void Player::Init()
{
	rect = Rectangle{ Program::ScreenWidth / 2, Program::GroundHeight, 30.0, 30.0 };
	speed = 450;
	carriedCoal = 0;
	m_lastDirection = 1;

	m_playerTex = LoadTexture("resources/Player.png");
	m_playerTexFlipped = LoadTexture("resources/PlayerFlipped.png");
	m_playerCoalTex = LoadTexture("resources/PlayerCoal.png");
	m_playerCoalTexFlipped = LoadTexture("resources/PlayerCoalFlipped.png");
}

void Player::Move(int direction)
{
	rect.x += direction * speed * GetFrameTime();
	rect.x = Clamp(rect.x, 250, 480);
	m_lastDirection = direction;
}

void Player::LoadCoal()
{
	carriedCoal = 5;
}

void Player::UnloadCoal()
{
	carriedCoal = 0;
}

void Player::Render()
{
	if (carriedCoal == 0)
	{
		if (m_lastDirection > 0)
			DrawTexture(m_playerTex, rect.x - 85, rect.y - 143, WHITE);
		else
			DrawTexture(m_playerTexFlipped, rect.x - 85, rect.y - 143, WHITE);
	}
	else
	{
		if (m_lastDirection > 0)
			DrawTexture(m_playerCoalTex, rect.x - 85, rect.y - 143, WHITE);
		else
			DrawTexture(m_playerCoalTexFlipped, rect.x - 85, rect.y - 143, WHITE);
	}
}

void Player::RenderInteractPopup()
{
	DrawText("SPACE", rect.x + rect.width / 2 - 5, rect.y - 30, 25, WHITE);
}
