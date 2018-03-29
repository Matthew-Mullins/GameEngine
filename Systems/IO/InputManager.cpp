#include "InputManager.h"

InputManager::InputManager() {}
InputManager& InputManager::Instance() {
	static InputManager instance;
	return instance;
}

bool InputManager::Initialize() {
	return true;
}

void InputManager::Update() {
	HandleKeyboard();
	HandleMouse();
	HandleGamepad();
}

void InputManager::HandleKeyboard() {

}

void InputManager::HandleMouse() {

}

void InputManager::HandleGamepad() {

}