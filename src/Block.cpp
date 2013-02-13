#include <iostream>
#include "Block.h"

Block::Block()
{

}

unsigned char Block::getMetadata()
{
	return(this->metadata);
}

void Block::setMetadata(unsigned char metadata)
{
	this->metadata = metadata;
}

void Block::Draw(short posX, short posY, short chunkPosX, short chunkPosY, sf::RenderWindow &app, TextureContainer &tc)
{
	sf::Sprite *tempSprite = &(tc.getTextures(getTextureName())[getTextureId()]);
	tempSprite->SetPosition((16*chunkPosX-16 + posX)*16, (16*chunkPosY-16  + posY)*16);
	app.Draw(*tempSprite);
}
