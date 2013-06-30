#include "BlockBackground.h"
#include "World.h"

<<<<<<< HEAD
BlockBackground::BlockBackground(unsigned short texture)
=======
BlockBackground::BlockBackground(unsigned short id) : Block(id)
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
{

}

std::string BlockBackground::getTextureName()
{
	return "BlockBackground.png";
}

unsigned char BlockBackground::getTextureId(App &app, unsigned short metadata)
{
	return metadata;
}

unsigned short BlockBackground::getId()
{
	return 2;
}

bool BlockBackground::isSeeThrough()
{
	return(false);
}

bool BlockBackground::isSolid()
{
	return(false);
}

unsigned char BlockBackground::getLayer()
{
	return 0;
}
