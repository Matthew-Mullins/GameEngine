#pragma once

#include "../Tools/Time.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class System {
public:
	virtual void Update(Time deltaTime, Time gameTime) = 0;
};