#include "Camera.h"

Camera::Camera(double speed)
{
	this->speed = speed;
	currentCreature = NULL;
}


Camera::~Camera(void)
{

}

void Camera::Update(sf::RenderWindow &app)
{
	if (currentCreature != NULL)
	{
		float deltaX = currentCreature->getX()+8-GetCenter().x;
		float deltaY = currentCreature->getY()+8-GetCenter().y;
		float speedFactor = atan(app.GetFrameTime()*speed)*2/3.14159265358979323846264338327950288419;

		SetCenter(GetCenter().x + deltaX*speedFactor, GetCenter().y + deltaY*speedFactor);
	}
}

void Camera::setCameraAt(Creature &creature)
{
	if (currentCreature != &creature)
		currentCreature = &creature;
}

void Camera::setSpeed(double speed)
{
	this->speed = speed;
}

sf::Vector2f Camera::getCreaturePosition()
{
	if(currentCreature != NULL)
		return(currentCreature->getPosition());
	else
		return(sf::Vector2f(0, 0));
}