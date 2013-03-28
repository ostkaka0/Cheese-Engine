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
	sf::Vector2f velocity;
	velocity.x = (float)cos(getAngle() * M_PI/180) * speed;
	velocity.y = -(float)sin(getAngle() * M_PI/180) * speed;

	sf::Vector2f position = getPosition();
	position.x += velocity.x * (app.GetFrameTime());
	position.y += velocity.y * (app.GetFrameTime());

	setPosition(position.x, position.y);
	Entity::Update(app,camera);
}

std::string Projectile::getTextureName() { return "arrow.png"; }
char Projectile::getTextureId() { return 0; }

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