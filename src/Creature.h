#pragma once

#include "Entity.h"
<<<<<<< HEAD
#include <SFML\Graphics.hpp>
=======
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d

class TextureContainer;
class Camera;

class Creature : public Entity
{
protected:
    float horizontal;
    float vertical;
public:
	Creature(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling);
<<<<<<< HEAD
	virtual void Update(sf::RenderWindow &app, Camera &camera, World &world);
=======
	virtual std::vector<unsigned char*>* Update(App& app, World &world);
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
};