#pragma once

#include <glm/glm.hpp>

struct Triangle {
	Triangle() : vertexIndex0(0), vertexIndex1(0), vertexIndex2(0) {}
	Triangle(unsigned short _v0, unsigned short _v1, unsigned short _v2) : vertexIndex0(_v0), vertexIndex1(_v1), vertexIndex2(_v2) {}
	unsigned short vertexIndex0;
	unsigned short vertexIndex1;
	unsigned short vertexIndex2;
};

class Mesh {
public:
	Mesh(size_t _triangleCount, size_t _vertexCount, Triangle* _triangles, glm::vec3* _vertices, glm::vec2* _uvs, glm::vec3* _normals)
		: triangleCount(_triangleCount), vertexCount(_vertexCount), triangles(_triangles), vertices(_vertices), uvs(_uvs), normals(_normals) {}

private:
	const size_t triangleCount;
	const size_t vertexCount;
	Triangle* triangles;
	glm::vec3* vertices;
	glm::vec2* uvs;
	glm::vec3* normals;
};