#pragma once
#include "Block.h"

class BlockBackground : public Block
{
public:
	BlockBackground(unsigned short);
	virtual unsigned short getId();
	virtual unsigned char getTextureId();
	virtual unsigned char getLayer();
	virtual std::string getTextureName();
	virtual bool isSeeThrough();
	virtual bool isSolid();
};

