#pragma once
#include "Chunk.h"
#include "Player.h"
#include "TextureContainer.h"
#include <iostream>
#define SCREENSIZEX 800
#define SCREENSIZEY 600

class World
{
private:
	short int sizeX;
	short int sizeY;
	Chunk *chunkList[256][256];
	int*  playerList;
public:
	World(unsigned short, unsigned short);
	~World(void);
	void Draw(sf::RenderWindow &app, TextureContainer &tc, Player &player);
	void setBlock(short x, short y, Block* block);
	Block* getBlock(short x, short y);
};

