#pragma once

#include "../System.h"
#include "../Game/Game.h"
#include "../Graphics/Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Gamepad.h"

class InputManager : public System {
public:
	static InputManager& Instance();

	bool Initialize();
	void Update() override;
private:
	//Prevent Copies or Instantiation of Multiple 'Game's
	InputManager();
	InputManager(const InputManager&) = delete;
	InputManager& operator= (const InputManager&) = delete;

	void HandleKeyboard();
	void HandleMouse();
	void HandleGamepad();
};