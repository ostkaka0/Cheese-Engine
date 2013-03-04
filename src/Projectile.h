#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Camera.h"
class Projectile
{
public:
	Projectile(sf::Vector2f position, float angle, float speed, sf::Sprite& sprite);
	~Projectile(void);
	virtual void Update(sf::RenderWindow& app, Camera& camera);
	virtual void Draw(sf::RenderWindow& app);
	void Rotate(float degrees);
	void setAngle(float angle);
	float getAngle();
	void setSpeed(float speed);
	float getSpeed();
	void setSize(sf::Vector2f& size);
	sf::Vector2f getSize();
	void setPosition(sf::Vector2f& position);
	sf::Vector2f getPosition();
	void setTexture(sf::Sprite& sprite);
	sf::Sprite* sprite;
private:
	float speed;
};

