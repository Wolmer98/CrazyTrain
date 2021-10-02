#pragma once

namespace Program
{
	const int ScreenWidth = 800;
	const int ScreenHeight = 450;

	void StartProgram();
	void CreateGameObjects();
	void CreateInputStates();
	void UpdateProgram();
	void CheckCollision();
	void CleanupProgram();
	void Render();
	void RestartGame();
}