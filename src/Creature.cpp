#include "Creature.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Camera.h"

#define PI 3.14159265358979323846264338

Creature::Creature(float x, float y, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling)
    {
        this->x = x;
        this->y = y;
        this->speed = speed;
        this->friction = friction;
        this->isClientControlling = isClientControlling;

        xSpeed = 0;
        ySpeed = 0;
        horizontal = 0;
        vertical = 0;
        angle = 0;
		this->spriteName = spriteName;
		this->spriteIndex = spriteIndex;
    }

void Creature::Update(sf::RenderWindow &app, sf::View &camera)
{
    xSpeed += horizontal * app.GetFrameTime();
    ySpeed += vertical * app.GetFrameTime();

    xSpeed *= 1 - tan(friction*PI/2) * app.GetFrameTime();
    ySpeed *= 1 - tan(friction*PI/2) * app.GetFrameTime();

    move(xSpeed * app.GetFrameTime(), ySpeed * app.GetFrameTime());
}

void Creature::Draw(sf::RenderWindow &app, TextureContainer &tc)
{
	sf::Sprite *sprite = &(tc.getTextures(spriteName)[spriteIndex]);
	if (sprite != NULL)
	{
		sprite->SetPosition(sf::Vector2f(x, y));
		sprite->SetRotation(angle);
		app.Draw(*sprite);
	}
	else
	{
		std::cout << "'" << getTextureName() << "' not found!" << std::endl;
	}
}

void Creature::move(float X, float Y)
{
    x += X;
    y += Y;
}
void Creature::setPosition(float X, float Y)
{
    x = X;
    y = Y;
}
void Creature::setX(float X) { x = X; }
void Creature::setY(float Y) { y = Y; }
float Creature::getX() { return x; }
float Creature::getY() { return y; }
