#include <string>

#include "Player.h"
#include "raylib.h"
#include "Program.h"

void Player::Init()
{
	rect = Rectangle{ Program::ScreenWidth / 2, Program::GroundHeight, 30.0, 30.0 };
	speed = 450;
	carriedCoal = 0;
}

void Player::Move(int direction)
{
	rect.x += direction * speed * GetFrameTime();
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
	DrawRectangleRec(rect, RED);
}

void Player::RenderInteractPopup()
{
	DrawText("E", rect.x + rect.width / 2 - 5, rect.y - 40, 20, BLACK);
}
