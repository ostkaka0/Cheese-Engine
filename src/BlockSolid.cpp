#include "BlockSolid.h"


BlockSolid::BlockSolid(unsigned short texture)
{
	this->setMetadata(texture);
}

std::string BlockSolid::getTextureName()
{
	return "BlockSolid.png";
}

unsigned char BlockSolid::getTextureId()
{
	return(getMetadata());
}

unsigned short BlockSolid::getId()
{
	return 1;
}

bool BlockSolid::isSeeThrough()
{
	return(false);
}

unsigned char BlockSolid::getLayer()
{
	return 2;
}
