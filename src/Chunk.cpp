#include "Chunk.h"

Chunk::Chunk()
{ 
	for (int x = 0; x < CHUNKWIDTH; x++)
	{
		for (int y = 0; y < CHUNKHEIGHT; y++)
		{
			blockList[x][y] = 0;
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
			if(blockList[x][y] == NULL || blockList[x][y]->isSeeThrough())
			{
				sf::Sprite *tempSprite = &(tc.getTextures("BlockBackground.png")[0]);
				tempSprite->SetPosition((16*xPos-16 + x)*16, (16*yPos-16  + y)*16);
				app.Draw(*tempSprite);
			}
			if(blockList[x][y] != NULL)
			{
				blockList[x][y]->Draw(x, y, xPos, yPos, app, tc);
			}
		}
	}
}

void Chunk::setBlock(unsigned short x, unsigned short y, Block &block)
{
	if(&block != NULL)
 	{
		if (blockList[x][y] != NULL)
		{
			delete blockList[x][y];
		}
 		blockList[x][y] = &block;
 	}
 	else
	{
		delete blockList[x][y];
 		blockList[x][y] = 0;
	}

}	

Block* Chunk::getBlock(unsigned short x, unsigned short y){return blockList[x][y];}
unsigned short Chunk::getBlockId(unsigned short x, unsigned short y){return blockList[x][y]->getId();}