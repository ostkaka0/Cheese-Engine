#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Creature.h"
#include "TextureContainer.h"

class Player : public Creature
{
private:
    bool right;
    bool down;
    bool left;
    bool up;
	float cameraDelay;
    std::string name;
public:
    Player(float X, float Y, bool IsClientControlling, std::string spriteName, int spriteIndex, std::string Name);
	virtual void Update(sf::RenderWindow &app, sf::View &camera);
    virtual void Draw(sf::RenderWindow &app, TextureContainer &tc);
    void KeyUpdate(bool Right, bool Down, bool Left, bool Up);
	virtual std::string getTextureName();
	virtual char getTextureId();
};

#endif