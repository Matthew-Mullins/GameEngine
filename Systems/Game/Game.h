#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../System.h"
#include "../../Entities/EntityManager.h"

enum GameState {
	GameMenu_Start = 0,
	GameMenu_Settings,
	GameMenu_Quit,
	GamePlaying,
	GamePaused_Resume,
	GamePaused_Settings,
	GamePaused_Exit
};

class Game : public System {
public:
	static Game& Instance();

	bool Initialize();
	void Update(Time deltaTime, Time gameTime) override;

	static GameState GetState();
	static void SetState(GameState _gameState);
	static bool IsState(GameState _gameState);

private:
	//Prevent Copies or Instantiation of Multiple 'Game's
	Game();
	Game(const Game&) = delete;
	Game& operator= (const Game&) = delete;

	//Game State Stuff
	static GameState currentGameState;
};