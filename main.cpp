#include <iostream>
#include <vector>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Systems/Game/Game.h"
#include "Systems/Graphics/Graphics.h"

#define WINDOW_TITLE "Window Title"

int main(int argc, char* argv[]) {

	//DeltaTime Variables
	Time deltaTime;
	Time currentTime = 0;
	Time lastTime = 0;
	Time gameTime = 0;

	//Vector of Systems
	std::vector<System*> systems;

	//Graphics Manager
	Graphics &graphicsManager = Graphics::Instance();
	if (!graphicsManager.Initialize(WINDOW_TITLE)) {
		std::cout << "Graphics Failed to Initialize - Terminating..." << std::endl;
		system("pause");
		return -1;
	}

	//Game Logic
	Game &game = Game::Instance();
	if (!game.Initialize()) {
		std::cout << "Game Failed to Initialize - Terminating..." << std::endl;
		system("pause");
		return -1;
	}

	//Add Systems to Queue
	systems.push_back(&game);
	systems.push_back(&graphicsManager);

	//Game Loop
	while (!glfwWindowShouldClose(graphicsManager.GetWindow())) {
		//Update DeltaTime
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		//Update GameTime
		if (game.IsState(GamePlaying)) {
			gameTime += deltaTime;
		}

		//Update Systems
		for (System* system : systems) {
			system->Update(deltaTime, gameTime);
		}
	}

	return 0;
}