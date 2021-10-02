#include <iostream>
#include <functional>
#include <vector>
#include <memory>

#include "InputManager.h"
#include "raylib.h"

std::vector<InputManager::InputState> m_inputStates;

InputManager::InputState InputManager::CreateState(std::string name)
{
	auto state = InputManager::InputState();
	state.name = name;

	return state;
}

InputManager::InputAction InputManager::CreateDownAction(int key, std::function<void()> action)
{
	auto inputAction = InputManager::InputAction();
	inputAction.key = key;
	inputAction.downAction = action;
	return inputAction;
}

InputManager::InputAction InputManager::CreateUpAction(int key, std::function<void()> action)
{
	auto inputAction = InputManager::InputAction();
	inputAction.key = key;
	inputAction.upAction = action;
	return inputAction;
}

InputManager::InputAction InputManager::CreateHoldAction(int key, std::function<void()> action)
{
	auto inputAction = InputManager::InputAction();
	inputAction.key = key;
	inputAction.holdAction = action;
	return inputAction;
}

void InputManager::PushState(InputManager::InputState inputState)
{
	m_inputStates.emplace_back(inputState);
}

void InputManager::PopState()
{
	m_inputStates.pop_back();
}

void InputManager::PollInput()
{
	std::vector<int> pressedKeys;

	for (auto it = m_inputStates.rbegin(); it != m_inputStates.rend(); ++it)
	{
		auto inputState = *it;
		for (auto inputAction : inputState.inputActions)
		{
			bool keyIsConsumed = std::find(pressedKeys.begin(), pressedKeys.end(), inputAction.key) != pressedKeys.end();
			if (keyIsConsumed)
				break;

			if (IsKeyPressed(inputAction.key) && inputAction.downAction != nullptr)
			{
				pressedKeys.emplace_back(inputAction.key);
				inputAction.downAction();
			}
			else if (IsKeyReleased(inputAction.key) && inputAction.upAction != nullptr)
			{
				pressedKeys.emplace_back(inputAction.key);
				inputAction.upAction();
			}
			else if (IsKeyDown(inputAction.key) && inputAction.holdAction != nullptr)
			{
				pressedKeys.emplace_back(inputAction.key);
				inputAction.holdAction();
			}
		}
	}
}