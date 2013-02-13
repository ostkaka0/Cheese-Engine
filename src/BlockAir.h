#pragma once
#include "Block.h"

class BlockAir: public Block
{
public:
	BlockAir();
	virtual	short int getId();
	virtual char getTextureId();
	virtual std::string getTextureName();
};

