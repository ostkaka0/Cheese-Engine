//class Entity;
#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include "App.h"
#ifdef _SERVER
#include <SFML\System.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

enum MessageType;
class TextureContainer;
class World;
class Camera;

class Entity
{
protected:
    float x;
    float y;
    float speedX;
    float speedY;
	int sizeX;
	int sizeY;
    float friction;
    float angle;
    float speed;
	std::string spriteName;
	int spriteIndex;
	void FixateX();
	void FixateY();
public:
    bool isClientControlling;
	Entity(float x, float y, short sizeX, short sizeY, float angle, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling);
	void Update(App& app, World* world, std::queue<std::pair<MessageType, unsigned char*>>* packetDataList);
#ifndef _SERVER
    virtual void Draw(App& app, TextureContainer &tc);
#endif
	virtual void CheckCollision(App& app, World* world);
	virtual void Collision(World* world);
	virtual std::string getTextureName()=0;
	virtual char getTextureId()=0;
    void setPosition(float x, float y);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
	float getAngle();
	void setAngle(float angle);
};
