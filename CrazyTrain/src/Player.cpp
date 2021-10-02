#include <string>

#include "Player.h"
#include "raylib.h"
#include <iostream>
void Player::Init()
{
	rect = Rectangle{ 0.0, 0.0, 30.0, 30.0 };
	speed = 450;
}

void Player::Move(int direction)
{
	rect.x += direction * speed * GetFrameTime();
}

void Player::Render()
{
	DrawRectangleRec(rect, RED);
}
