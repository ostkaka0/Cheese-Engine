#include <iostream>
#include "Block.h"
#include "TextureContainer.h"

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

bool Block::isSimple()
{
	return true;
}

void Block::Draw(short posX, short posY, sf::RenderWindow &app, TextureContainer &tc)
{
	sf::Sprite *tempSprite = &(tc.getTextures(getTextureName())[getTextureId()]);
	tempSprite->SetPosition(posX*16, posY*16);
	app.Draw(*tempSprite);
}
