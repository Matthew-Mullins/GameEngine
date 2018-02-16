#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

#include "../Game/Game.h"
#include "../Graphics/Graphics.h"

class Mouse {
public:
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void CursorPosCallback(GLFWwindow* window, double _x, double _y);

	static glm::vec2 GetCursorPos();
private:
	static void HandleInput();
	static void HandleCursor();

	static bool ButtonPressed(int button);
	static bool ButtonDown(int button);
	static bool ButtonReleased(int button);

	static bool buttonPressed[];
	static bool buttonDown[];
	static bool buttonReleased[];

	static glm::vec2 cursorPosition;
};