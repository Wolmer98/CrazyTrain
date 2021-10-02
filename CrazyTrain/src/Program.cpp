#include <iostream>
#include <memory>
#include <functional>

#include "Program.h"
#include "raylib.h"
#include "InputManager.h"
#include "Player.h"

std::shared_ptr<Player> player;

void Program::StartProgram()
{

    InitWindow(ScreenWidth, ScreenHeight, "CrazyTrain");
    SetTargetFPS(0);

    CreateGameObjects();
    CreateInputStates();
}

void Program::CreateGameObjects()
{
    player = std::make_shared<Player>();
    player->Init();
}

void Program::CreateInputStates()
{
    auto playerInputState = InputManager::CreateState("PlayerInputState");
    auto moveRightAction = InputManager::CreateHoldAction(KEY_D, []() { player->Move(1); });
    auto moveLeftAction = InputManager::CreateHoldAction(KEY_A, []() { player->Move(-1); });
    playerInputState.AddAction(moveRightAction);
    playerInputState.AddAction(moveLeftAction);
    InputManager::PushState(playerInputState);
}

void Program::UpdateProgram()
{
    while (!WindowShouldClose())
    {
        InputManager::PollInput();
        Render();
    }
}

void Program::CheckCollision()
{
    
}

void Program::Render()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    player->Render();

    EndDrawing();
}

void Program::CleanupProgram()
{
    CloseWindow();
}

void Program::RestartGame()
{

}