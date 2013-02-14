#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureContainer.h"

class Block
{
private:
	unsigned char metadata;
public:
	Block(void);
	unsigned char getMetadata();
	void setMetadata(unsigned char);

    virtual unsigned short getId()=0;
	virtual unsigned char getTextureId()=0;
	virtual unsigned char getLayer()=0;
	virtual std::string getTextureName()=0;
	virtual bool isSeeThrough()=0;
	virtual bool isSolid()=0;
	//virtual char getSubTextureId() = 0;
	void Draw(short posX, short posY, short chunkPosX, short chunkPosY, sf::RenderWindow &app, TextureContainer &tc);
};

