#include "player.h"
#include "World.h"
#include "Camera.h"
#include "Projectile.h"

Player::Player(float X, float Y, short sizeX, short sizeY, bool IsClientControlling, std::string spriteName, int spriteIndex, std::string Name) 
	: Creature(X, Y, sizeX, sizeY, 4096, 0.875, spriteName, spriteIndex, IsClientControlling)
{
	name = Name;
	cameraDelay = 0;
	right = false;
	down = false;
	left = false;
	up = false;
	lmb = false;
}

void Player::Update(sf::RenderWindow &app, Camera &camera, World &world)
{
	if (isClientControlling)
	{
		KeyUpdate(
			app.GetInput().IsKeyDown(sf::Key::D),
			app.GetInput().IsKeyDown(sf::Key::S),
			app.GetInput().IsKeyDown(sf::Key::A),
			app.GetInput().IsKeyDown(sf::Key::W));

		if(!lmb && (lmb=app.GetInput().IsMouseButtonDown(sf::Mouse::Left)))
		{
			//double angle = atan2((camera.GetCenter().y + app.GetInput().GetMouseY() - 256) - (camera.getEntityPosition().y+8), (camera.GetCenter().x + app.GetInput().GetMouseX() - 384) - (camera.getEntityPosition().x+8)) * 180 / 3.1415;
			double angle = atan2((camera.GetCenter().y + app.GetInput().GetMouseY() - 256) - (y+8), (camera.GetCenter().x + app.GetInput().GetMouseX() - 384) - (x+8)) * 180 / 3.1415;
			if (angle < 0)
				angle = angle + 360;
			//Projectile *projectile = new Projectile(camera.getEntityPosition().x, camera.getEntityPosition().y, 32, 32, -angle, 512, 0, "arrow.png", 0, false);
			Projectile *projectile = new Projectile(x+8, y+8, 32, 32, -angle, 512, 0, "arrow.png", 0, false);
			world.AddEntity(projectile);//new Projectile(sf::Vector2f(camera.getCreaturePosition().x+8, camera.getCreaturePosition().y+8), (float)angle, 500, tc.getTextures("arrowb.png")[0]));
			cameraDelay = 2.0F;
			camera.setCameraAt(*projectile);
		}

		if (&camera.getEntity() != this)
		{
			if (cameraDelay <= 0)
			{
				camera.setCameraAt(*this);
				cameraDelay = 0.5;
			}
			else
			{
				cameraDelay -= app.GetFrameTime();
			}
		}
	}

	Creature::Update(app, camera, world);
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