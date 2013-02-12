#include <SFML\Graphics.hpp>
#include "Creature.h"
#include "Monster.h"


Monster::Monster(float x, float y, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling) : Creature(x, y, speed, friction, spriteName, spriteIndex, isClientControlling)
{
}


Monster::~Monster(void)
{
}

void Monster::Update(sf::RenderWindow &App)
{

}