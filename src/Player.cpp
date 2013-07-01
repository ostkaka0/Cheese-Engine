#include "player.h"
#include "World.h"
#include "camera.h"
#include "Projectile.h"

Player::Player(float X, float Y, short sizeX, short sizeY, bool IsClientControlling, std::string spriteName, int spriteIndex, std::string Name) 
	: Creature(X, Y, sizeX, sizeY, 40960, 0.875, spriteName, spriteIndex, IsClientControlling)
{
	name = Name;
	cameraDelay = 0;
	right = false;
	down = false;
	left = false;
	up = false;
	lmb = false;
}

void Player::Update(App& app, World* world, std::queue<std::pair<MessageType, unsigned char*>>* packetDataList)
{
#ifndef _SERVER
	if (isClientControlling)
	{
		KeyUpdate(
			app.GetInput().IsKeyDown(sf::Key::D),
			app.GetInput().IsKeyDown(sf::Key::S),
			app.GetInput().IsKeyDown(sf::Key::A),
			app.GetInput().IsKeyDown(sf::Key::W));

		if(!lmb && (lmb=app.GetInput().IsMouseButtonDown(sf::Mouse::Left)))
		{
			//double angle = atan2((GetCamera(app).GetCenter().y + app.GetInput().GetMouseY() - 256) - (GetCamera(app).getEntityPosition().y+8), (GetCamera(app).GetCenter().x + app.GetInput().GetMouseX() - 384) - (GetCamera(app).getEntityPosition().x+8)) * 180 / 3.1415;
			double angle = atan2((GetCamera(app).GetCenter().y + app.GetInput().GetMouseY() - 256) - (y+8), (GetCamera(app).GetCenter().x + app.GetInput().GetMouseX() - 384) - (x+8)) * 180 / 3.1415;
			if (angle < 0)
				angle = angle + 360;

			double deltaSpeedX = cos(angle*3.1415926535)*speedX;
			double deltaSpeedY = sin(angle*3.1415926535)*speedY;

			if (angle > 180)
				deltaSpeedX *= -1;

			if (angle < 90 || angle > 270)
				deltaSpeedY *= -1;

			
			//Projectile *projectile = new Projectile(GetCamera(app).getEntityPosition().x.getEntityPosition().y, 32, 32, -angle, 512, 0, "arrow.png", 0, false);
			Projectile *projectile = new Projectile(x+8, y+8, 32, 32, -angle, 1024, 0.03125, "arrow.png", 0, false);
			world->AddEntity(projectile);//new Projectile(sf::Vector2f(GetCamera(app).getCreaturePosition().x+8.getCreaturePosition().y+8), (float)angle, 500, tc.getTextures("arroaaawb.png")[0]));
			cameraDelay = 0.03125F;
			//GetCamera(app).setCameraAt(*projectile);
		}

		lmb = app.GetInput().IsMouseButtonDown(sf::Mouse::Left);

		if (&GetCamera(app).getEntity() != this)
		{
			if (cameraDelay <= 0)
			{
				GetCamera(app).setCameraAt(*this);
				cameraDelay = 0.5;
			}
			else
			{
				cameraDelay -= app.GetFrameTime();
			}
		}
	}
#endif

	Creature::Update(app, world, packetDataList);
}

#ifndef _SERVER
void Player::Draw(App& app, TextureContainer &tc)
{
	Creature::Draw(app, tc);
}
#endif

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

void Player::setCameraDelay(float delay)
{
	cameraDelay = delay;
}

std::string Player::getTextureName()
{
	return "graywizard.png";
}

char Player::getTextureId()
{
	return 0;
}