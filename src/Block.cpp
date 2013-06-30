#include <iostream>
#include <typeinfo>
#include "Block.h"
#include "TextureContainer.h"

Block::Block(unsigned short id)
{
	this->id = id;
}

std::function<Block*(unsigned short)> Block::RegisterBlock(const unsigned short id)
{
	std::cout << typeid(*this).name() << '(' << typeid(*this).hash_code() << ") registered with blockId " << id << ".\n";
	return [&](unsigned short metadata) { return this; };
}

unsigned short Block::getId()
{
	return id;
}

bool Block::isSimple()
{
	return true;
}

<<<<<<< HEAD
bool Block::isSimple()
{
	return true;
}

void Block::Draw(short posX, short posY, sf::RenderWindow &app, TextureContainer &tc)
=======
#ifndef _SERVER
void Block::Draw(int posX, int posY, App& app, TextureContainer &tc, unsigned short metadata)
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
{
	sf::Sprite *&&tempSprite = &(tc.getTextures(getTextureName())[getTextureId(app, metadata)]);
	tempSprite->SetPosition(posX, posY);
	app.Draw(*tempSprite);
}
#endif
