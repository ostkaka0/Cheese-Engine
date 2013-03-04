#include "Projectile.h"
#define _USE_MATH_DEFINES
#include <math.h>


Projectile::Projectile(sf::Vector2f position, float angle, float speed, sf::Sprite& sprite)
{
	this->sprite = new sf::Sprite(sprite);
	this->setPosition(position);
	this->setAngle(angle);
	this->setSpeed(speed);
}


Projectile::~Projectile(void)
{
}

void Projectile::Update(sf::RenderWindow& app, Camera& camera)
{ 
	sf::Vector2f direction;
	direction.x = (float)cos(sprite->GetRotation() * M_PI/180);
	direction.y = -(float)sin(sprite->GetRotation() * M_PI/180);

	sf::Vector2f velocity;
	velocity.x = direction.x * speed;
	velocity.y = direction.y * speed;

	sf::Vector2f position = sprite->GetPosition();
	position.x += velocity.x * (app.GetFrameTime());
	position.y += velocity.y * (app.GetFrameTime());

	setPosition(position);
}

void Projectile::Draw(sf::RenderWindow& app)
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
