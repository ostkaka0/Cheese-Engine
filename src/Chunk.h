#pragma once
#define CHUNKWIDTH 16
#define CHUNKHEIGHT 16
#include "Block.h"
#include "BlockSolid.h"
#include "BlockBackground.h"
#include "BlockGravity.h"
#include "Player.h"
#include "TextureContainer.h"
#include <SFML/Graphics.hpp>

class Chunk
{
private:
	Block* blockList[CHUNKWIDTH][CHUNKHEIGHT][6];
	bool drawBackground;
	sf::Sprite *backgroundSprite;
public:
	Chunk();
	~Chunk(void);
	Block* getHighestBlock(unsigned char x, unsigned char y);
	Block* getBlock(unsigned char layer, unsigned short, unsigned short);
	void setBlock(unsigned char layer, unsigned short, unsigned short, Block&);
	unsigned short getBlockId(unsigned char layer, unsigned short x, unsigned short y);
	void Draw(short xPos, short yPos, sf::RenderWindow &app, TextureContainer &tc, Camera &camera);
	bool isAnySolid(Block* blocks[6]);
	bool isAnySeeThrough(Block* blocks[6]);
};

