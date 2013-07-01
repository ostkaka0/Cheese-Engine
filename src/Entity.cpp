#include <math.h>

#include "Entity.h"
#include "TextureContainer.h"
#include "World.h"
#include "Block.h"

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

void Entity::Update(App& app, World* world, std::queue<sf::Packet>* packetDataList)
{
	CheckCollision(app, world);

    x += speedX * app.GetFrameTime();
	y += speedY * app.GetFrameTime();

	

	speedX *= 1 - tan(friction*M_PI/2) * app.GetFrameTime();
    speedY *= 1 - tan(friction*M_PI/2) * app.GetFrameTime();
}

void Entity::CheckCollision(App& app, World* world)
{
	/*if (world.isBlockSolid((int)(x+1+speedX*app.GetFrameTime())>>4,(int)(y+1)>>4) ||
		world.isBlockSolid((int)(x+14+speedX*app.GetFrameTime())>>4,(int)(y+1)>>4) ||
		world.isBlockSolid((int)(x+1+speedX*app.GetFrameTime())>>4,(int)(y+14)>>4) ||
		world.isBlockSolid((int)(x+14+speedX*app.GetFrameTime())>>4,(int)(y+14)>>4))
	{
		speedX = 0;
		Collision(world);
	}

	if (world.isBlockSolid((int)(x+1)>>4,(int)(y+1+speedY*app.GetFrameTime())>>4) ||
		world.isBlockSolid((int)(x+14)>>4,(int)(y+1+speedY*app.GetFrameTime())>>4) ||
		world.isBlockSolid((int)(x+1)>>4,(int)(y+14+speedY*app.GetFrameTime())>>4) ||
		world.isBlockSolid((int)(x+14)>>4,(int)(y+14+speedY*app.GetFrameTime())>>4))
	{
		speedY = 0;
		Collision(world);
	}

	if (world.isBlockSolid((int)(x+1+speedX*app.GetFrameTime())>>4,(int)(y+1+speedY*app.GetFrameTime())>>4) ||
		world.isBlockSolid((int)(x+14+speedX*app.GetFrameTime())>>4,(int)(y+1+speedY*app.GetFrameTime())>>4) ||
		world.isBlockSolid((int)(x+1+speedX*app.GetFrameTime())>>4,(int)(y+14+speedY*app.GetFrameTime())>>4) ||
		world.isBlockSolid((int)(x+14+speedX*app.GetFrameTime())>>4,(int)(y+14+speedY*app.GetFrameTime())>>4))
	{
		if (abs(speedX) > abs(speedY))
			speedX = 0;
		else
			speedY = 0;

		CheckCollision(app, world);
		Collision(world);
	}*/

	/*bool solid[2][2] = {{
		world.isBlockSolid((int)(x)>>4,(int)(y)>>4),
		world.isBlockSolid((int)(x+15)>>4,(int)(y)>>4)},{
		world.isBlockSolid((int)(x)>>4,(int)(y+16)>>4),
		world.isBlockSolid((int)(x+15)>>4,(int)(y+16)>>4)}};

	if (!solid[0][0] || !solid[1][0] || !solid[0][1] || !solid[1][1])
	{
		if (abs(speedX) > abs(speedY))
		{
			if (speedX > 0 && (solid[1][0] || solid[1][1]))//if (solid[0][0] || solid[1][0] || solid[0][1] || solid[1][1])
			{
				FixateX();

				if (speedY > 0 && solid[1][1])//if (solid[0][0] || solid[1][0] || solid[0][1] || solid[1][1])
					FixateY();
				else if (solid[1][0])
					FixateY();
			}
			else if (solid[0][0] || solid[0][1])
			{
				FixateX();

				if (speedY > 0 && solid[0][1])//if (solid[0][0] || solid[1][0] || solid[0][1] || solid[1][1])
					FixateY();
				else if (solid[0][0])
					FixateY();
			}
		}
		else
		{
			if (speedY > 0 && (solid[0][1] || solid[1][1]))//if (solid[0][0] || solid[1][0] || solid[0][1] || solid[1][1])
			{
				FixateY();

				if (speedX > 0 && solid[1][1])//if (solid[0][0] || solid[1][0] || solid[0][1] || solid[1][1])
					FixateX();
				else if (solid[0][1])
					FixateX();
			}
			else if (solid[0][0] || solid[1][0])
			{
				FixateY();

				if (speedX > 0 && solid[1][0])//if (solid[0][0] || solid[1][0] || solid[0][1] || solid[1][1])
					FixateX();
				else if (solid[0][0])
					FixateX();
			}
		}
	}*/
}

void Entity::Collision(World* world)
{

}

void Entity::FixateX()
{
	if (speedX > 0)
	{
		x = (int)x+4>>4<<4;
	}
	else
	{
		x = (int)(x+12)>>4<<4;
	}
	speedX = 0;
}

void Entity::FixateY()
{
	if (speedY > 0)
	{
		y = (int)y+4>>4<<4;
	}
	else
	{
		y = (int)(y+12)>>4<<4;
	}
	speedY = 0;
}

#ifndef _SERVER
void Entity::Draw(App& app, TextureContainer &tc)
{
	sf::Sprite *sprite = &(tc.getTextures(spriteName)[spriteIndex]);
	if (sprite != nullptr)
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
#endif

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
