#include "Component.h"

ComponentType Component::GetType() {
	return type;
}

void Component::SetType(ComponentType _type) {
	type = _type;
}

bool Component::IsType(ComponentType _type) {
	return type == _type;
}