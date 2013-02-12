#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <SFML\Graphics.hpp>
#include "TextureContainer.h"

class Creature
{
protected:
    float x;
    float y;
    float xSpeed;
    float ySpeed;
    float horizontal;
    float vertical;
    float friction;
    float angle;
    float speed;
    bool isClientControlling;
	std::string spriteName;
	int spriteIndex;
public:
	Creature(float x, float y, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling);
	virtual void Update(sf::RenderWindow &app, sf::View &camera);
    virtual void Draw(sf::RenderWindow &app, TextureContainer &tc);
	virtual std::string getTextureName()=0;
	virtual char getTextureId()=0;
    void move(float x, float y);
    void setPosition(float x, float y);
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
};

#endif
