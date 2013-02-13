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
	return(getMetadata()); //Metadata säger vilken 16x16 sprite/16x16 textur blocket får
}

short int BlockSolid::getId()
{
	return 1;
}

bool BlockSolid::isSeeThrough()
{
	return(false);
}
