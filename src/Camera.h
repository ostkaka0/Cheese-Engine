#pragma once
#include <SFML/Graphics.hpp>
#include "Creature.h"

class Camera : public sf::View
{
private:
	Creature *currentCreature;
public:
	Camera(void);
	~Camera(void);
	void Update();
	void setCameraAt(Creature &creature);
};

