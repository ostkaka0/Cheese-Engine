class Camera;
#pragma once
#include <SFML/Graphics.hpp>

class Entity;

class Camera : public sf::View
{
private:
	Entity *currentEntity;
	double speed;
public:
	Camera(double speed);
	~Camera(void);
	void Update(sf::RenderWindow &app);
	void setCameraAt(Entity &entity);
	void setSpeed(double speed);
	sf::Vector2f getEntityPosition();
	Entity &Camera::getEntity();
};

