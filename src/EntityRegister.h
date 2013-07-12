#pragma once

#include <string>
#include <map>
#include <functional>

class TextureContainer;
class Entity;

class EntityRegister
{
	std::map<size_t, std::function<Entity*(/*EventCallback*/)>> blockTypeList;
public:
	EntityRegister();
	void RegisterEntity(TextureContainer tC, Entity* entity, size_t typeId);
	Entity* getEntityType(unsigned short id, unsigned short metadata);
	Entity* getEntityTypeByTypeId(size_t typeId, unsigned short metadata);
};