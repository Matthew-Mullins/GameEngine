#include "Mouse.h"

bool Mouse::buttonPressed[GLFW_MOUSE_BUTTON_LAST] = { false };
bool Mouse::buttonDown[GLFW_MOUSE_BUTTON_LAST] = { false };
bool Mouse::buttonReleased[GLFW_MOUSE_BUTTON_LAST] = { false };

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