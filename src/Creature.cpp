#include "Entity.h"
#include "Creature.h"

#define PI 3.14159265358979323846264338

Creature::Creature(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling) 
	: Entity(x,y,sizeX,sizeY,0,speed,friction,spriteName,spriteIndex,isClientControlling)
{
	horizontal = 0;
    vertical = 0;
}

void Creature::Update(sf::RenderWindow &app, sf::View &camera)
{
    speedX += horizontal * app.GetFrameTime();
    speedY += vertical * app.GetFrameTime();

    Entity::Update(app, camera);
}