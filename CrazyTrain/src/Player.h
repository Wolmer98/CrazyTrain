#pragma once
#include "raylib.h" // TODO: Replace with header class definition, though

class Player
{
public:
	void Init();
	void Move(int direction);
	void LoadCoal();
	void UnloadCoal();

	void Render();
	void RenderInteractPopup();

	Rectangle rect;
	std::string spritePath;
	float speed;
	int carriedCoal;

	bool showInteractPopup;
};