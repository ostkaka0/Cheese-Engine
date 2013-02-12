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
		this->SetCenter(currentCreature->getX()*speed*app.GetFrameTime()+this->GetCenter().x*(1-speed)+8,currentCreature->getY()*speed+this->GetCenter().y*(1-speed*app.GetFrameTime())+8);
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