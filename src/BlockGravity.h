#pragma once
#include "Block.h"

class BlockGravity : public Block
{
public:
	BlockGravity(short int texture);
	virtual	short int getId()=0;
	virtual char getTextureId()=0;
	virtual std::string getTextureName()=0;
	virtual bool isSeeThrough()=0;
	virtual void getGravityModifierAngle()=0;
	virtual void getGravityStrength()=0;
	virtual void getFrictionStrength()=0;
};

