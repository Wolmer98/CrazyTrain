#pragma once
#include <memory>

namespace Program
{
	const int ScreenWidth = 800;
	const int ScreenHeight = 450;
	const int GroundHeight = ScreenHeight / 2 + 100;

	void StartProgram();
	void CreateGameObjects();
	void CreateInputStates();
	void UpdateProgram();
	void CheckInteraction();
	std::shared_ptr<void> GetInteractiveObject();
	void CleanupProgram();
	void Render();
	void RestartGame();
}