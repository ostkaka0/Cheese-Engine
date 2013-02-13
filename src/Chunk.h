#pragma once
#define CHUNKWIDTH 16
#define CHUNKHEIGHT 16
#include "Block.h"
#include "BlockSolid.h"
#include "BlockAir.h"
#include "Player.h"
#include "TextureContainer.h"
#include <SFML/Graphics.hpp>

class Chunk
{
private:
	Block* blockList[CHUNKWIDTH][CHUNKHEIGHT];
public:
	Chunk();
	~Chunk(void);
	Block* getBlock(unsigned short, unsigned short);
	void setBlock(unsigned short, unsigned short, Block&);
	unsigned short getBlockId(unsigned short x, unsigned short y);
	void Draw(short xPos, short yPos, sf::RenderWindow &app, TextureContainer &tc);
};

