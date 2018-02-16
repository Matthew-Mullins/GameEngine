#include "Entity.h"

Entity::Entity(bool _isDynamic, std::string _tag){
	SetTag(_tag);
	isDynamic = _isDynamic;
	AddComponent(new Transform());
}

Entity::~Entity() {
	for (Component* component : components) {
		delete component;
	}
}

//ID Stuff
int Entity::GetId() const{
	return id;
}

void Entity::SetId(int _id) {
	id = _id;
}

bool Entity::HasId(int _id) const{
	return id == _id;
}

//Tag Stuff
std::string Entity::GetTag() const {
	return tag;
}

void Entity::SetTag(std::string _tag) {
	tag = _tag;
}

bool Entity::HasTag(std::string _tag) const {
	return tag == _tag;
}

//Component Stuff
void Entity::AddComponent(Component* _component) {
	for (Component* component : components) {
		if (component->IsType(_component->GetType())) {
			std::cout << "Entity With Tag: " << GetTag() << " and ID: " << GetId() << " Already Has A " << _component->GetType() << " Component." << std::endl;
			return;
		}
	}
	components.push_back(_component);
}

void Entity::RemoveComponent(Component* _component) {
	auto iterator = std::find(components.begin(), components.end(), _component);
	if (iterator != components.end()) {
		components.erase(iterator);
	}
}

Component* Entity::GetComponentOfType(ComponentType _type) {
	for (auto iterator = components.begin(); iterator != components.end(); iterator++) {
		if ((*iterator)->IsType(_type)) {
			return (*iterator);
		}
	}
	return nullptr;
}