#pragma once
#include "Block.h"

class BlockSolid : public Block
{
public:
	BlockSolid(short int);
	virtual	short int getId();
	virtual char getTextureId();
	virtual std::string getTextureName();
	virtual bool isSeeThrough();
};

