#pragma once

#include "Creature.h"

class Monster : public Creature
{
public:
	Monster(float X, float Y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool IsClientControlling);
    ~Monster(void);
	virtual void Update(App& app, World* world, std::vector<unsigned char*>* packetDataList);
};