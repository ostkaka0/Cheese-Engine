#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include "Entity.h"
#include <SFML\Graphics.hpp>
#include "TextureContainer.h"

class Creature : public Entity
{
protected:
    float horizontal;
    float vertical;
public:
	Creature(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling);
	virtual void Update(sf::RenderWindow &app, sf::View &camera);
};

#endif
