#include "Mouse.h"

bool Mouse::buttonPressed[GLFW_MOUSE_BUTTON_LAST] = { false };
bool Mouse::buttonDown[GLFW_MOUSE_BUTTON_LAST] = { false };
bool Mouse::buttonReleased[GLFW_MOUSE_BUTTON_LAST] = { false };

glm::vec2 Mouse::cursorPosition = glm::vec2(0.0f, 0.0f);

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	//Check Valid Mouse Button
	if (button < 0) {
		return;
	}

	//Check for Button Pressed
	if (action == GLFW_PRESS && buttonDown[button] == false) {
		buttonPressed[button] = true;
		buttonReleased[button] = false;
	}
	
	//Check for Button Released
	if (action == GLFW_RELEASE && buttonDown[button] == true) {
		buttonDown[button] = false;
		buttonReleased[button] = true;
	}

	//Check for Button Down
	buttonDown[button] = (action != GLFW_RELEASE);
	HandleInput();
}

void Mouse::CursorPosCallback(GLFWwindow* window, double _x, double _y) {
	if (cursorPosition.x != _x || cursorPosition.y != _y) {
		cursorPosition = glm::vec2(_x, _y);
		HandleCursor();
	}
}

glm::vec2 Mouse::GetCursorPos() {
	return cursorPosition;
}

void Mouse::HandleInput() {
	Game& gameInstance = Game::Instance();
	Graphics& graphicsInstance = Graphics::Instance();
	if (ButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
		std::cout << "Left Button Pressed" << std::endl;
	}

	if (ButtonPressed(GLFW_MOUSE_BUTTON_RIGHT)) {
		std::cout << "Right Button Pressed" << std::endl;
	}
}

void Mouse::HandleCursor() {
	std::cout << glm::to_string(cursorPosition) << std::endl;
}

bool Mouse::ButtonPressed(int button) {
	bool tmp = buttonPressed[button];
	buttonPressed[button] = false;
	return tmp;
}

bool Mouse::ButtonDown(int button) {
	return buttonDown[button];
}

bool Mouse::ButtonReleased(int button) {
	bool tmp = buttonReleased[button];
	buttonReleased[button] = false;
	return tmp;
}