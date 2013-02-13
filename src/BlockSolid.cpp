#include "BlockSolid.h"


BlockSolid::BlockSolid(short int texture)
{
	this->setMetadata(texture);
}

std::string BlockSolid::getTextureName()
{
	return "BlockSolid.png";
}

char BlockSolid::getTextureId()
{
	return(getMetadata());
}

short int BlockSolid::getId()
{
	return 1;
}

bool BlockSolid::isSeeThrough()
{
	return(false);
}
