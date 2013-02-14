#include "BlockBackground.h"


BlockBackground::BlockBackground(unsigned short texture)
{
	this->setMetadata(texture);
}

std::string BlockBackground::getTextureName()
{
	return "BlockBackground.png";
}

unsigned char BlockBackground::getTextureId()
{
	return(getMetadata());
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
