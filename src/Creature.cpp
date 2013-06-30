#include "Creature.h"

#define PI 3.141592653589793238462643383279502884197169399375105820974944

Creature::Creature(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling) 
	: Entity(x,y,sizeX,sizeY,0,speed,friction,spriteName,spriteIndex,isClientControlling)
{
	horizontal = 0;
    vertical = 0;
}

void Creature::Update(App& app, World* world, std::vector<unsigned char*>* packetDataList)
{
    speedX += horizontal * app.GetFrameTime();
    speedY += vertical * app.GetFrameTime();

    Entity::Update(app, world, packetDataList);
}