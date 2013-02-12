#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "Creature.h"

class Monster : public Creature
{
public:
	Monster(float X, float Y, float speed, float friction, std::string spriteName, int spriteIndex, bool IsClientControlling);
    ~Monster(void);
	virtual void Update(sf::RenderWindow &App);
};

#endif