#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <new>

//Components
#include "../Components/Transform.h"

class Entity {
	friend class EntityManager;
public:
	int GetId() const;
	void SetId(int _id);
	bool HasId(int _id) const;

	std::string GetTag() const;
	void SetTag(std::string _tag);
	bool HasTag(std::string _tag) const;

	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);

	Component* GetComponentOfType(ComponentType _type);
private:
	Entity(bool _isDynamic = false, std::string _tag = NULL);
	~Entity();

	int id;
	std::string tag;
	bool isDynamic;

	std::vector<Component*> components;
};