#pragma once

#include "Component.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>


class Transform : public Component {
public:
	Transform();
	Transform(glm::vec3 _position, glm::vec3 _scale, glm::quat _quatRotation);
	Transform(glm::vec3 _position, glm::vec3 _scale, glm::vec3 _eulerRotation);
	Transform(glm::vec3 _position, glm::vec3 _scale, glm::vec3 _axis, float _angleRadians);

	static const glm::vec3 FORWARD;
	static const glm::vec3 RIGHT;
	static const glm::vec3 UP;

	//Basic Data Getters and Setters
	glm::vec3 GetPosition();
	void SetPosition(glm::vec3 _position);
	glm::vec3 GetScale();
	void SetScale(glm::vec3 _scale);
	glm::quat GetRotation();
	void SetRotation(glm::quat _rotation);
	void SetRotation(glm::vec3 _rotation);
	void SetRotation(glm::vec3 _axis, float _angleRadians);

	//Basic Data Operators
	void Translate(glm::vec3 _translation);
	void Scale(glm::vec3 _scale);
	void Rotate(glm::quat _rotation);
	void Rotate(glm::vec3 _rotation);
	void Rotate(glm::vec3 _axis, float _angleRadians);

	//Output Data Getters
	glm::mat4 GetTranslationMatrix();
	glm::mat4 GetScalingMatrix();
	glm::mat4 GetRotationMatrix();
	glm::mat4 GetTransformationMatrix();
private:
	//Basic Data
	glm::vec3 position;
	glm::vec3 scale;
	glm::quat rotation;

	//Matrices
	glm::mat4 translationMatrix;
	glm::mat4 scalingMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 transformationMatrix;
	void UpdateTransformationMatrix();
};