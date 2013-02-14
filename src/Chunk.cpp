#include "Chunk.h"

Chunk::Chunk()
{ 
	for(int l = 0; l < 6; l++)
	{
		for (int x = 0; x < CHUNKWIDTH; x++)
		{
			for (int y = 0; y < CHUNKHEIGHT; y++)
			{
				blockList[x][y][l] = 0;
			}
		}
	}
}			

Chunk::~Chunk(void)
{
	for(int l = 0; l < 6; l++)
	{
		for (int i = 0; i < CHUNKWIDTH; i++)
		{
			for (int j = 0; j < CHUNKHEIGHT; j++)
			{
				delete this->blockList[i][j][l];
			}
		}
	}
}

bool isAnySolid(Block* blocks[6])
{
	for(int l = 0; l < 6; l++)
	{
		if(blocks[l] != NULL && blocks[l]->isSolid())
			return true;
	}
	return false;
}

bool isAnySeeThrough(Block* blocks[6])
{
	for(int l = 0; l < 6; l++)
	{
		if(blocks[l] != NULL && blocks[l]->isSeeThrough())
			return true;
	}
	return false;
}

void Chunk::Draw(short xPos, short yPos, sf::RenderWindow &app, TextureContainer &tc)
{
	backgroundSprite = &(tc.getTextures("BlockBackground.png")[0]);
	for(short x = 0; x < CHUNKWIDTH; x++)
	{
		for(short y = 0; y < CHUNKHEIGHT; y++)
		{
			if(blockList[x][y][0] == NULL)
			{
				backgroundSprite->SetPosition((16*xPos-16 + x)*16, (16*yPos-16  + y)*16);
				app.Draw(*backgroundSprite);
			}
			for(int l = 0; l < 6; l++)
			{
				if(blockList[x][y][l] != NULL)
				{
					blockList[x][y][l]->Draw(x, y, xPos, yPos, app, tc); 
				}
			}
		}
	}
}

void Chunk::setBlock(unsigned char layer, unsigned short x, unsigned short y, Block &block)
{
	if(&block != NULL)
	{
		if (blockList[x][y][layer] != NULL)
		{
			delete blockList[x][y][layer];
		}
		blockList[x][y][layer] = &block;
	}
	else
	{
		delete blockList[x][y][layer];
		blockList[x][y][layer] = 0;
	}

}	

Block* Chunk::getBlock(unsigned char layer, unsigned short x, unsigned short y){return blockList[x][y][layer];}
unsigned short Chunk::getBlockId(unsigned char layer, unsigned short x, unsigned short y){return blockList[x][y][layer]->getId();}