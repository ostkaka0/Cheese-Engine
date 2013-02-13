#include "BlockAir.h"


BlockAir::BlockAir()
{
}

std::string BlockAir::getTextureName()
{
	return "";
}

char BlockAir::getTextureId()
{
	return(0); //Metadata säger vilken 16x16 sprite/16x16 textur blocket får
}

short int BlockAir::getId()
{
	return 0;
}
