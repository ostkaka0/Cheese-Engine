#pragma once
#include "Block.h"

class BlockSolid : public Block
{
public:
	BlockSolid(unsigned short);
	virtual unsigned short getId();
	virtual unsigned char getTextureId();
	virtual unsigned char getLayer();
	virtual std::string getTextureName();
	virtual bool isSeeThrough();
};

