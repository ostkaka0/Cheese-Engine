#include "Camera.h"

Camera::Camera(double speed)
{
	this->speed = speed;
	currentEntity = NULL;
}


Camera::~Camera(void)
{

}

void Camera::Update(sf::RenderWindow &app)
{
	if (currentEntity != NULL)
	{
		float deltaX = currentEntity->getX()+8-GetCenter().x;
		float deltaY = currentEntity->getY()+8-GetCenter().y;
		float speedFactor = atan(app.GetFrameTime()*speed)*2/3.14159265358979323846264338327950288419;

		SetCenter(GetCenter().x + deltaX*speedFactor, GetCenter().y + deltaY*speedFactor);
	}
}

void Camera::setCameraAt(Entity &entity)
{
	if (currentEntity != &entity)
		currentEntity = &entity;
}

void Camera::setSpeed(double speed)
{
	this->speed = speed;
}

sf::Vector2f Camera::getEntityPosition()
{
	if(currentEntity != NULL)
		return(currentEntity->getPosition());
	else
		return(sf::Vector2f(0, 0));
}

Entity &Camera::getEntity() { return *currentEntity; }