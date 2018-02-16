#pragma once

#include <iostream>

#include "../System.h"
#include "../Game/Game.h"

#include "../IO/Keyboard.h"
#include "../IO/Mouse.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

class Graphics : public System {
public:
	static Graphics& Instance();

	bool Initialize(char* windowTitle);
	void Update(Time deltaTime, Time gameTime) override;

	GLFWwindow* GetWindow() const;
private:
	//Prevent Copies or Instantiation of Multiple 'Graphics's
	Graphics();
	Graphics(const Graphics&) = delete;
	Graphics& operator= (const Graphics&) = delete;

	//Variables
	GLFWwindow* window;
	int windowWidth = 1024;
	int windowHeight = 768;

	static const glm::vec3 SKY_COLOR;
};