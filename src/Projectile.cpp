#include "Projectile.h"
#include "Entity.h"
#define _USE_MATH_DEFINES
#include <math.h>


Projectile::Projectile(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling) : Entity(x,y,sizeX,sizeY,speed,friction,spriteName,spriteIndex,isClientControlling)
{
}


Projectile::~Projectile(void)
{
}

void Projectile::Update(sf::RenderWindow& app, Camera& camera)
{ 
	speedX = (float)cos(angle * M_PI/180)*speed;
	speedY = (float)sin(angle * M_PI/180)*speed;
	Entity::Update(app,camera);

	/*sf::Vector2f direction;
	direction.x = (float)cos(sprite->GetRotation() * M_PI/180);
	direction.y = -(float)sin(sprite->GetRotation() * M_PI/180);

	sf::Vector2f velocity;
	velocity.x = direction.x * speed;
	velocity.y = direction.y * speed;

	sf::Vector2f position = sprite->GetPosition();
	position.x += velocity.x * (app.GetFrameTime());
	position.y += velocity.y * (app.GetFrameTime());

	setPosition(position);*/
}

/*void Projectile::Draw(sf::RenderWindow& app)
{
	app.Draw(*sprite);
}

void Projectile::Rotate(float degrees)
{
	sprite->Rotate(degrees);
}

void Projectile::setAngle(float angle)
{
	sprite->SetRotation(-angle);
}

void Projectile::setSpeed(float speed)
{
	if(speed >= 0)
	{
		this->speed = speed;
	}
}

void Projectile::setPosition(sf::Vector2f& position)
{
	sprite->SetPosition(position);
}

void Projectile::setTexture(sf::Sprite& sprite)
{
	this->sprite->SetImage(*(sprite.GetImage()));
}

void Projectile::setSize(sf::Vector2f& size)
{
	sprite->Resize(size);
}

float Projectile::getAngle() {return sprite->GetRotation();}
sf::Vector2f Projectile::getPosition() {return sprite->GetPosition();}
float Projectile::getSpeed() {return speed;}
sf::Vector2f Projectile::getSize() {return sprite->GetSize();}
*/