#include "Creature.h"

#define PI 3.141592653589793238462643383279502884197169399375105820974944

Creature::Creature(float x, float y, short sizeX, short sizeY, float speed, float friction, std::string spriteName, int spriteIndex, bool isClientControlling) 
	: Entity(x,y,sizeX,sizeY,0,speed,friction,spriteName,spriteIndex,isClientControlling)
{
	horizontal = 0;
    vertical = 0;
}

<<<<<<< HEAD
void Creature::Update(sf::RenderWindow &app, Camera &camera, World &world)
=======
std::vector<unsigned char*>* Creature::Update(App& app, World &world)
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
{
    speedX += horizontal * app.GetFrameTime();
    speedY += vertical * app.GetFrameTime();

<<<<<<< HEAD
    Entity::Update(app, camera, world);
=======
    return Entity::Update(app, world);
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
}