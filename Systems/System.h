#pragma once

#include "../Tools/Time/Time.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class System {
public:
	virtual void Update() = 0;
};