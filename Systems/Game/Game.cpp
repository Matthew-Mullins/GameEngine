#include "Game.h"

Time Game::deltaTime = 0;
Time Game::gameTime = 0;

Game::Game() {}
Game &Game::Instance() {
	static Game instance;
	return instance;
}

bool Game::Initialize() {
	return true;
}

void Game::Update() {
	//Update Delta Time
	Time lastTime = 0, currentTime = 0;
	currentTime = glfwGetTime();
	deltaTime = currentTime.GetTimeSeconds() - lastTime.GetTimeSeconds();
	lastTime = currentTime.GetTimeSeconds();	
}

Time Game::GetDeltaTime() {
	return deltaTime;
}

Time Game::GetGameTime() {
	return gameTime;
}