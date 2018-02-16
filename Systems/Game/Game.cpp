#include "Game.h"

GameState Game::currentGameState = GameMenu_Start;

Game::Game() {}
Game &Game::Instance() {
	static Game instance;
	return instance;
}

bool Game::Initialize() {
	EntityManager::AddEntity(false);
	EntityManager::AddEntity();
	return true;
}

void Game::Update(Time deltaTime, Time gameTime) {

}

//Game State Stuff
GameState Game::GetState() {
	return currentGameState;
}

void Game::SetState(GameState _gameState) {
	currentGameState = _gameState;
}

bool Game::IsState(GameState _gameState) {
	return currentGameState == _gameState;
}