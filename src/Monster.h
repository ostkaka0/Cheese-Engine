#pragma once

#include "Creature.h"

class Monster : public Creature
{
public:
	Monster(float X, float Y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool IsClientControlling);
    ~Monster(void);
<<<<<<< HEAD
	virtual void Update(sf::RenderWindow &app, Camera &camera, World &world);
=======
	virtual std::vector<unsigned char*>* Update(App& app, World &world);
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
};