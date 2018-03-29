#pragma once

#include "Component.h"
#include "../../Systems/Graphics/Material/Material.h"
#include "../../Systems/Graphics/Mesh/Mesh.h"
#include "../../Systems/Graphics/Texture/Texture.h"

#include <glm/glm.hpp>

class MeshComponent : public Component {
public:
	MeshComponent(std::string _meshFilename, Material* _material);
	MeshComponent(std::string _meshFilename, std::string _materialFilename);
	MeshComponent(std::string _meshFilename, std::string _materialFilename, std::string _textureFilename);
	MeshComponent(MeshComponent* _meshComponent);

	Material* GetMaterial() const;
	void SetMaterial(Material* _material);
	Mesh* GetMesh() const;
	void SetMesh(Mesh* _mesh);
	Texture* GetTexture() const;
	void SetTexture(Texture* _texture);
	glm::vec2 GetUvScale() const;
	void SetUvScale(glm::vec2 _uvScale);
private:
	Material* material;
	Mesh* mesh;
	Texture* texture;
	glm::vec2 uvScale;
};