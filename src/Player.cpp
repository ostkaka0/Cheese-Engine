#include "player.h"
#include <string>
#include <list>
#include <SFML/Graphics.hpp>

Player::Player(float X, float Y, short sizeX, short sizeY, bool IsClientControlling, std::string spriteName, int spriteIndex, std::string Name) 
	: Creature(X, Y, sizeX, sizeY, 4096,0.875, spriteName, spriteIndex, IsClientControlling)
{
    name = Name;
	cameraDelay = 0;
    right = false;
    down = false;
    left = false;
    up = false;
}

void Player::Update(sf::RenderWindow &app, Camera &camera)
{
    if (isClientControlling)
    {
        KeyUpdate(
            app.GetInput().IsKeyDown(sf::Key::D),
            app.GetInput().IsKeyDown(sf::Key::S),
            app.GetInput().IsKeyDown(sf::Key::A),
            app.GetInput().IsKeyDown(sf::Key::W));

		if (cameraDelay <= 0)
		{
			camera.setCameraAt(*this);
		}
		else
		{
			cameraDelay -= app.GetFrameTime();
		} 
	}

    Creature::Update(app, camera);
}

void Player::Draw(sf::RenderWindow &app, TextureContainer &tc)
{
    Creature::Draw(app, tc);
}

void Player::KeyUpdate(bool Right, bool Down, bool Left, bool Up)
{
    if (Right != right || Down != down || Left != left || Up != up)
    {
        horizontal = 0;
        vertical = 0;

        if (Right)  horizontal += speed;
        if (Down)   vertical += speed;
        if (Left)   horizontal -= speed;
        if (Up)     vertical -= speed;

        right = Right;
        down = Down;
        left = Left;
        up = Up;

        if (isClientControlling)
        {
            
        }
    }
}

std::string Player::getTextureName()
{
	return "graywizard.png";
}

char Player::getTextureId()
{
	return 0;
}