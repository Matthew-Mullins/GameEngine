#pragma once

#include <string>

enum ComponentType {
	Transform_Component = 0
};

class Component {
public:
	ComponentType GetType();
	void SetType(ComponentType _type);
	bool IsType(ComponentType _type);
private:
	ComponentType type;
};