
#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include "Creature.h"

class TextureContainer;
class Camera;
class Projectile;

class Player : public Creature
{
private:
    bool right;
    bool down;
    bool left;
    bool up;
	bool lmb;
	float cameraDelay;
    std::string name;
public:
    Player(float X, float Y, short sizeX, short sizeY, bool IsClientControlling, std::string spriteName, int spriteIndex, std::string Name);
	void Update(App& app, World* world, std::queue<std::pair<MessageType, unsigned char*>>* packetDataList);
#ifndef _SERVER
    virtual void Draw(App& app, TextureContainer &tc);
#endif
    void KeyUpdate(bool Right, bool Down, bool Left, bool Up, std::queue<std::pair<MessageType, unsigned char*>>* packetDataList);
	void setCameraDelay(float delay);
	virtual std::string getTextureName();
	virtual char getTextureId();
};
