#include "Camera.h"
#include <math.h>

#define PI 3.14159265358979323846264338327950288419

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
		this->SetCenter(
		(currentCreature->getX()+8)*speed/atan(app.GetFrameTime()*PI)+
		this->GetCenter().x*(1-speed/atan(app.GetFrameTime()*PI)),
		(currentCreature->getY()+8)*speed*app.GetFrameTime()+
		this->GetCenter().y*(1-speed*app.GetFrameTime()));
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