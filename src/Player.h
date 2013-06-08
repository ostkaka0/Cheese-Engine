
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
	virtual void Update(sf::RenderWindow &app, Camera &camera, World &world);
    virtual void Draw(sf::RenderWindow &app, TextureContainer &tc);
    void KeyUpdate(bool Right, bool Down, bool Left, bool Up);
	void setCameraDelay(float delay);
	virtual std::string getTextureName();
	virtual char getTextureId();
};
