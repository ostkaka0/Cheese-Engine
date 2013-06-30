#include <SFML\Graphics.hpp>
#include "Creature.h"
#include "Monster.h"


Monster::Monster(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling) : Creature(x, y, sizeX, sizeY, speed, friction, spriteName, spriteIndex, isClientControlling)
{
}


Monster::~Monster(void)
{
}

<<<<<<< HEAD
void Monster::Update(sf::RenderWindow &app, Camera &camera, World &world)
{
	Creature::Update(app, camera, world);
=======
std::vector<unsigned char*>* Monster::Update(App& app, World &world)
{
	return Creature::Update(app, world);
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
}