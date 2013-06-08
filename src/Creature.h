#pragma once

#include "Entity.h"
#include <SFML\Graphics.hpp>

class TextureContainer;
class Camera;

class Creature : public Entity
{
protected:
    float horizontal;
    float vertical;
public:
	Creature(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling);
	virtual void Update(sf::RenderWindow &app, Camera &camera, World &world);
};