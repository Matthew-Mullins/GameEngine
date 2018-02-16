#include "Keyboard.h"

bool Keyboard::keyPressed[GLFW_KEY_LAST] = { false };
bool Keyboard::keyDown[GLFW_KEY_LAST] = { false };
bool Keyboard::keyReleased[GLFW_KEY_LAST] = { false };

void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//Check Valid Key
	if (key < 0) {
		std::cout << "Invalid Key Pressed" << std::endl;
		return;
	}
	
	//Check for Key Pressed
	if (action == GLFW_PRESS && keyDown[key] == false) {
		keyPressed[key] = true;
		keyReleased[key] = false;
	}
	//Check for Key Released
	if (action == GLFW_RELEASE && keyDown[key] == true) {
		keyPressed[key] = false;
		keyReleased[key] = true;
	}

	//Check for Key Down
	keyDown[key] = (action != GLFW_RELEASE);
	HandleInput();
}

void Keyboard::HandleInput() {
	Game& gameInstance = Game::Instance();
	Graphics& graphicsInstance = Graphics::Instance();
	
	if (KeyPressed(GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(graphicsInstance.GetWindow(), true);
	}

	if (KeyPressed(GLFW_KEY_ENTER)) {

	}
}

bool Keyboard::KeyPressed(int key) {
	bool tmp = keyPressed[key];
	keyPressed[key] = false;
	return tmp;
}

bool Keyboard::KeyDown(int key) {
	return keyDown[key];
}

bool Keyboard::KeyReleased(int key) {
	bool tmp = keyReleased[key];
	keyReleased[key] = false;
	return tmp;
}