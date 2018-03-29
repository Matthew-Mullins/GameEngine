#pragma once

#include "../Game/Game.h"
#include "../Graphics/Graphics.h"

class Keyboard {
public:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
	static bool KeyPressed(int key);
	static bool KeyDown(int key);
	static bool KeyReleased(int key);

	static bool keyPressed[];
	static bool keyDown[];
	static bool keyReleased[];
};