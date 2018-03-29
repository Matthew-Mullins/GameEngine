#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Texture {
public:
	Texture(GLuint _textureId, size_t _width, size_t _height)
		: textureId(_textureId), width(_width), height(_height) {}
private:
	GLuint textureId;
	size_t width;
	size_t height;
};