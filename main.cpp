#include <iostream>
#include <vector>

#include "Systems/Graphics/Graphics.h"
#include "Systems/Game/Game.h"
#include "Systems/IO/InputManager.h"

#define WINDOW_TITLE "Window Title"

int main(int argc, char* argv[]) {
	//Vector of Systems
	std::vector<System*> systems;
	systems.clear();

	//Graphics Manager - Draw()
	Graphics &graphicsManager = Graphics::Instance();
	if (!graphicsManager.Initialize(WINDOW_TITLE)) {
		std::cout << "Graphics Failed to Initialize - Terminating..." << std::endl;
		system("pause");
		return -1;
	}

	//Game Logic - Update()
	Game &gameManager = Game::Instance();
	if (!gameManager.Initialize()) {
		std::cout << "Game Failed to Initialize - Terminating..." << std::endl;
		system("pause");
		return -1;
	}

	//Input Manager - Input()
	InputManager &inputManager = InputManager::Instance();
	if (!inputManager.Initialize()) {
		std::cout << "InputManager Failed to Initialize - Terminating..." << std::endl;
		system("pause");
		return -1;
	}

	//Add Systems to Queue
	systems.push_back(&inputManager);
	systems.push_back(&gameManager);
	systems.push_back(&graphicsManager);

	//Game Loop
	while (!glfwWindowShouldClose(graphicsManager.GetWindow())) {
		//Update Systems
		for (System* system : systems) {
			system->Update();
		}
	}

	return 0;
}