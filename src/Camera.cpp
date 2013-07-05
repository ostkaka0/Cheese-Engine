#ifndef _SERVER
#include "camera.h"
#include "Entity.h"

Camera::Camera(double speed)
{
	this->speed = speed;
	currentEntity = nullptr;
}


Camera::~Camera(void)
{

}

void Camera::Update(App& app)
{
	if (currentEntity != nullptr)
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
	if(currentEntity != nullptr)
		return(currentEntity->getPosition());
	else
		return(sf::Vector2f(0, 0));
}

Entity &Camera::getEntity() { return *currentEntity; }
#endif