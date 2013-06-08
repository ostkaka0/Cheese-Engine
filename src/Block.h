#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class TextureContainer;

class Block
{
private:
	unsigned char metadata;
public:
	Block();
	unsigned char getMetadata();
	void setMetadata(unsigned char);
    virtual unsigned short getId()=0;
	virtual unsigned char getTextureId()=0;
	virtual unsigned char getLayer()=0;
	virtual std::string getTextureName()=0;
	virtual bool isSeeThrough()=0;
	virtual bool isSolid()=0;
	virtual bool isSimple();
	//virtual char getSubTextureId() = 0;
	void Draw(short posX, short posY, sf::RenderWindow &app, TextureContainer &tc);
};