#include <iostream>
#include <memory>
#include <functional>

#include "raylib.h"
#include "raymath.h"

#include "Program.h"
#include "InputManager.h"
#include "Player.h"
#include "CoalDeposit.h"
#include "TrainFurnace.h"
#include "Train.h"

std::shared_ptr<Player> m_player;
std::shared_ptr<CoalDeposit> m_coalDeposit;
std::shared_ptr<Train> m_train;
std::shared_ptr<TrainFurnace> m_trainFurnace;

std::shared_ptr<void> m_currentInteractiveObject;

void Program::StartProgram()
{

    InitWindow(ScreenWidth, ScreenHeight, "CrazyTrain");
    SetTargetFPS(0);

    CreateGameObjects();
    CreateInputStates();
}

void Program::CreateGameObjects()
{
    m_player = std::make_shared<Player>();
    m_player->Init();
    m_coalDeposit = std::make_shared<CoalDeposit>();
    m_coalDeposit->Init();
    m_trainFurnace = std::make_shared<TrainFurnace>();
    m_trainFurnace->Init();
    m_train = std::make_shared<Train>();
    m_train->Init(m_trainFurnace);
}

void Program::CreateInputStates()
{
    auto playerInputState = InputManager::CreateState("PlayerInputState");
    auto moveRightAction = InputManager::CreateHoldAction(KEY_D, []() { m_player->Move(1); });
    auto moveLeftAction = InputManager::CreateHoldAction(KEY_A, []() { m_player->Move(-1); });
    auto interactAction = InputManager::CreateDownAction(KEY_E, []() { CheckInteraction(); });
    playerInputState.AddAction(moveRightAction);
    playerInputState.AddAction(moveLeftAction);
    playerInputState.AddAction(interactAction);
    InputManager::PushState(playerInputState);
}

void Program::UpdateProgram()
{
    while (!WindowShouldClose())
    {
        InputManager::PollInput();
        m_currentInteractiveObject = GetInteractiveObject();
        m_player->showInteractPopup = m_currentInteractiveObject != nullptr;

        m_trainFurnace->Update();
        m_train->Update();

        //std::cout << "Power: " << m_trainFurnace->power << "\n";
        Render();
    }
}

void Program::CheckInteraction()
{
    if (m_currentInteractiveObject == m_coalDeposit)
        m_player->LoadCoal();
    else if (m_currentInteractiveObject == m_trainFurnace)
    {
        m_trainFurnace->LoadCoal(m_player->carriedCoal);
        m_player->UnloadCoal();
    }
}

std::shared_ptr<void> Program::GetInteractiveObject()
{
    if (abs(m_player->rect.x - m_coalDeposit->rect.x) < m_coalDeposit->rect.width)
    {
        return m_coalDeposit;
    }
    else if (abs(m_player->rect.x - m_trainFurnace->rect.x) < m_trainFurnace->rect.width)
        return m_trainFurnace;

    return nullptr;
}

void Program::Render()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    m_train->Render();
    m_coalDeposit->Render();
    m_trainFurnace->Render();
    
    m_player->Render();
    if (m_player->showInteractPopup)
        m_player->RenderInteractPopup();

    EndDrawing();
}

void Program::CleanupProgram()
{
    CloseWindow();
}

void Program::RestartGame()
{
    m_player->Init();
    m_coalDeposit->Init();
    m_trainFurnace->Init();
    m_train->Init(m_trainFurnace);
}