#pragma once

#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../System.h"
#include "../../Entities/Entity/EntityManager.h"

class Game : public System {
public:
	static Game& Instance();
	
	bool Initialize();
	void Update() override;

	static Time GetDeltaTime();
	static Time GetGameTime();

private:
	//Prevent Copies or Instantiation of Multiple 'Game's
	Game();
	Game(const Game&) = delete;
	Game& operator= (const Game&) = delete;

	//Time Variables
	static Time deltaTime;
	static Time gameTime;
};