#include "Entity.h"


#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Camera.h"

#define PI 3.14159265358979323846264338

Entity::Entity(float x, float y, short sizeX, short sizeY, float angle, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling)
{
        this->x = x;
        this->y = y;
        this->speed = speed;
        this->friction = friction;
        this->isClientControlling = isClientControlling;

        speedX = 0;
        speedY = 0;
		this->sizeX = sizeX;
		this->sizeY = sizeY;

        this->angle = angle;
		this->spriteName = spriteName;
		this->spriteIndex = spriteIndex;
}

void Entity::Update(sf::RenderWindow &app, sf::View &camera)
{
    x += speedX * app.GetFrameTime();
	y += speedY * app.GetFrameTime();

	speedX *= 1 - tan(friction*PI/2) * app.GetFrameTime();
    speedY *= 1 - tan(friction*PI/2) * app.GetFrameTime();
}

void Entity::Draw(sf::RenderWindow &app, TextureContainer &tc)
{
	sf::Sprite *sprite = &(tc.getTextures(spriteName)[spriteIndex]);
	if (sprite != NULL)
	{
		sprite->SetPosition(getPosition());
		sprite->SetRotation(getAngle());
		app.Draw(*sprite);
	}
	else
	{
		std::cout << "'" << getTextureName() << "' not found!" << std::endl;
	}
}

void Entity::setPosition(float X, float Y)
{
    x = X;
    y = Y;
}

sf::Vector2f Entity::getPosition() { return(sf::Vector2f(x, y)); }
void Entity::setX(float X) { x = X; }
void Entity::setY(float Y) { y = Y; }
float Entity::getX() { return x; }
float Entity::getY() { return y; }
sf::Vector2f Entity::getSize() { return sf::Vector2f(sizeX, sizeY); }
void Entity::setAngle(float angle) {this->angle = angle; }
float Entity::getAngle() { return angle;  }
