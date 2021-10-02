#pragma once
#include "raylib.h" // TODO: Replace with header class definition, though

class Player
{
public:
	void Init();
	void Move(int direction);
	void Render();

	Rectangle rect;
	std::string spritePath;
	float speed;
};