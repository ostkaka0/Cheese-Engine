#pragma once

#include <string>
#include <map>
#include <functional>

class TextureContainer;
class Entity;

class BlockRegister
{
	std::map<size_t, std::function<Entity*(/*EventCallback*/)>> blockTypeList;
public:
	BlockRegister();
	void RegisterEntity(TextureContainer tC, Entity* entity, size_t typeId);
	Entity* getEntityType(unsigned short id, unsigned short metadata);
	Entity* getEntityTypeByTypeId(size_t typeId, unsigned short metadata);
};