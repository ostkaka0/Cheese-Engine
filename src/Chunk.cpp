#include "Chunk.h"

Chunk::Chunk()
{ 
	for (int x = 0; x < CHUNKWIDTH; x++)
	{
		for (int y = 0; y < CHUNKHEIGHT; y++)
		{
			this->blockList[x][y] = new BlockSolid(0);
		}
	}
}			

Chunk::~Chunk(void)
{
	for (int i = 0; i < CHUNKWIDTH; i++)
	{
		for (int j = 0; j < CHUNKHEIGHT; j++)
		{
			delete this->blockList[i][j];
		}
	}
}

void Chunk::Draw(short xPos, short yPos, sf::RenderWindow &app, TextureContainer &tc)
{
	for(short x = 0; x < CHUNKWIDTH; x++)
	{
		for(short y = 0; y < CHUNKHEIGHT; y++)
		{
			blockList[x][y]->Draw(x, y, xPos, yPos, app, tc);
		}
	}
}

void Chunk::setBlock(unsigned short x, unsigned short y, Block &block)
{
	*blockList[x][y] = block;
}

Block* Chunk::getBlock(unsigned short x, unsigned short y){return blockList[x][y];}
unsigned short Chunk::getBlockId(unsigned short x, unsigned short y){return blockList[x][y]->getId();}