#include "MeshComponent.h"

MeshComponent::MeshComponent(std::string _meshFilename, Material* _material) {

}

MeshComponent::MeshComponent(std::string _meshFilename, std::string _materialFilename) {

}

MeshComponent::MeshComponent(std::string _meshFilename, std::string _materialFilename, std::string _textureFilename) {

}

MeshComponent::MeshComponent(MeshComponent* _meshComponent) {
	material = _meshComponent->GetMaterial();
	mesh = _meshComponent->GetMesh();
	texture = _meshComponent->GetTexture();
	uvScale = _meshComponent->GetUvScale();
}

Material* MeshComponent::GetMaterial() const {
	return material;
}

void MeshComponent::SetMaterial(Material* _material) {
	material = _material;
}

Mesh* MeshComponent::GetMesh() const {
	return mesh;
}

void MeshComponent::SetMesh(Mesh* _mesh) {
	mesh = _mesh;
}

Texture* MeshComponent::GetTexture() const {
	return texture;
}

void MeshComponent::SetTexture(Texture* _texture) {
	texture = _texture;
}

glm::vec2 MeshComponent::GetUvScale() const {
	return uvScale;
}

void MeshComponent::SetUvScale(glm::vec2 _uvScale) {
	uvScale = _uvScale;
}