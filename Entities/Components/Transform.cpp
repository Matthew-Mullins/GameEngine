#include "Transform.h"

const glm::vec3 Transform::FORWARD = glm::vec3(0.0f, 0.0f, 1.0f);
const glm::vec3 Transform::RIGHT = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 Transform::UP = glm::vec3(0.0f, 1.0f, 0.0f);

Transform::Transform() : Transform(glm::vec3(), glm::vec3(1.0f), glm::quat()){
}

Transform::Transform(glm::vec3 _position, glm::vec3 _scale, glm::quat _rotation) {
	SetType(Transform_Component);
	SetPosition(_position);
	SetScale(_scale);
	SetRotation(_rotation);
}

Transform::Transform(glm::vec3 _position, glm::vec3 _scale, glm::vec3 _rotation) {
	SetType(Transform_Component);
	SetPosition(_position);
	SetScale(_scale);
	SetRotation(_rotation);
}

Transform::Transform(glm::vec3 _position, glm::vec3 _scale, glm::vec3 _axis, float _angleRadians) {
	SetType(Transform_Component);
	SetPosition(_position);
	SetScale(_scale);
	SetRotation(_axis, _angleRadians);
}

//Basic Data Getters and Setters
glm::vec3 Transform::GetPosition() {
	return position;
}

void Transform::SetPosition(glm::vec3 _position) {
	position = _position;
	transformationMatrix = glm::translate(glm::mat4(), position);
	UpdateTransformationMatrix();
}

glm::vec3 Transform::GetScale() {
	return scale;
}

void Transform::SetScale(glm::vec3 _scale) {
	scale = _scale;
	scalingMatrix = glm::scale(scale);
	UpdateTransformationMatrix();
}

glm::quat Transform::GetRotation() {
	return rotation;
}

void Transform::SetRotation(glm::quat _rotation) {
	rotation = _rotation;
	rotationMatrix = glm::toMat4(rotation);
	UpdateTransformationMatrix();
}

void Transform::SetRotation(glm::vec3 _rotation) {
	SetRotation(glm::quat(_rotation));
}

void Transform::SetRotation(glm::vec3 _axis, float _angleRadians) {
	SetRotation(glm::angleAxis(_angleRadians, _axis));
}

//Basic Data Operators
void Transform::Translate(glm::vec3 _translation) {
	SetPosition(position + _translation);
}

void Transform::Scale(glm::vec3 _scale) {
	SetScale(scale * _scale);
}

void Transform::Rotate(glm::quat _rotation) {
	SetRotation(_rotation * rotation);
}

void Transform::Rotate(glm::vec3 _rotation) {
	Rotate(glm::quat(_rotation));
}

void Transform::Rotate(glm::vec3 _axis, float _angleRadians) {
	SetRotation(glm::rotate(rotation, glm::degrees(_angleRadians), _axis));
}

//Output Data Getters
glm::mat4 Transform::GetTranslationMatrix() {
	return translationMatrix;
}

glm::mat4 Transform::GetScalingMatrix() {
	return scalingMatrix;
}

glm::mat4 Transform::GetRotationMatrix() {
	return rotationMatrix;
}

glm::mat4 Transform::GetTransformationMatrix() {
	return transformationMatrix;
}

void Transform::UpdateTransformationMatrix() {
	transformationMatrix = transformationMatrix * rotationMatrix * scalingMatrix;
}