#pragma once

#include "Entity/Entity.h"

class EntityManager {
public:
	//Find Entities
	static Entity* FindEntityWithId(int _id);
	static std::vector<Entity*> FindEntitiesWithTag(std::string _tag);
	static std::vector<Entity*> GetEntities();

	//Add or Remove Entities
	static void AddEntity(bool _isDynamic = false, std::string _tag = "");
	static void RemoveEntity(int _id);
	static void RemoveEntity(Entity* _entity);
private:
	static int nextEntityId;

	static std::vector<Entity*> entities;
};