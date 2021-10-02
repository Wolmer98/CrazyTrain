#pragma once
#include <vector>

namespace InputManager
{
	struct InputAction
	{
		int key;
		std::function<void()> downAction;
		std::function<void()> upAction;
		std::function<void()> holdAction;
	};
	struct InputState
	{
		std::string name;
		std::vector<InputAction> inputActions;

		void AddAction(InputAction& action)
		{
			inputActions.emplace_back(action);
		}
	};

	InputState CreateState(std::string name);
	InputAction CreateDownAction(int key, std::function<void()> action);
	InputAction CreateUpAction(int key, std::function<void()> action);
	InputAction CreateHoldAction(int key, std::function<void()> action);
	void PushState(InputState inputState);
	void PopState();
	void PollInput();
};