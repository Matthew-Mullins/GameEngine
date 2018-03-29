#include "EntityManager.h"

int EntityManager::nextEntityId = 0;

std::vector<Entity*> EntityManager::entities;

Entity* EntityManager::FindEntityWithId(int _id) {
	for (Entity* entity : entities) {
		if (entity->GetId() == _id) {
			return entity;
		}
	}
	std::cout << "Could Not Find Entity With Id: " << _id << std::endl;
	return nullptr;
}

std::vector<Entity*> EntityManager::FindEntitiesWithTag(std::string _tag) {
	std::vector<Entity*> findEntities;
	for (Entity* entity : entities) {
		if (entity->GetTag() == _tag) {
			findEntities.push_back(entity);
		}
	}
	return findEntities;
}

std::vector<Entity*> EntityManager::GetEntities() {
	return entities;
}

void EntityManager::AddEntity(bool _isDynamic, std::string _tag) {
	Entity* entity = new Entity(_isDynamic, _tag);
	entity->SetId(nextEntityId);
	nextEntityId++;
	entities.push_back(entity);
}

void EntityManager::RemoveEntity(int _id) {
	Entity* _entity = FindEntityWithId(_id);
	if (_entity != nullptr) {
		delete _entity;
	} else {
		std::cout << "Could Not Remove Entity With Id: " << _id << std::endl;
	}
}

void EntityManager::RemoveEntity(Entity* _entity) {
	RemoveEntity(_entity->GetId());
}