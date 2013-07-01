#pragma once

#include "Entity.h"

class TextureContainer;
class Camera;

class Creature : public Entity
{
protected:
    float horizontal;
    float vertical;
public:
	Creature(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling);
	void Update(App& app, World* world, std::queue<std::pair<MessageType, unsigned char*>>* packetDataList);
	void CreatureMove(float x, float y, float speedX, float speedY, float angle, float horizontal, float vertical);
};