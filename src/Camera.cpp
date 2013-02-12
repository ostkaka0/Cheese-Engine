#include "Camera.h"


Camera::Camera(void)
{
	currentCreature = NULL;
}


Camera::~Camera(void)
{

}

void Camera::Update()
{
	if (currentCreature != NULL)
		this->SetCenter(currentCreature->getX()+8,currentCreature->getY()+8);
}

void Camera::setCameraAt(Creature &creature)
{
	if (currentCreature != &creature)
		currentCreature = &creature;
}