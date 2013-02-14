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
				//blockList[x][y][l] = new BlockSolid(2);
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

bool Chunk::isAnySolid(Block* blocks[6])
{
	for(int l = 0; l < 6; l++)
	{
		if(blocks[l] != NULL && blocks[l]->isSolid())
			return true;
	}
	return false;
}

bool Chunk::isAnySeeThrough(Block* blocks[6])
{
	for(int l = 0; l < 6; l++)
	{
		if(blocks[l] != NULL && blocks[l]->isSeeThrough())
			return true;
	}
	return false;
}

Block* Chunk::getHighestBlock(unsigned char x, unsigned char y)
{
	for(int l = 5; l >= 0; l--)
	{
		if(blockList[x][y][l] != NULL)
			return blockList[x][y][l];
	}
	return(0);
}

void Chunk::Draw(short xPos, short yPos, sf::RenderWindow &app, TextureContainer &tc)
{
	backgroundSprite = &(tc.getTextures("Block0.png")[0]);
	for(short x = 0; x < CHUNKWIDTH; x++)
	{
		for(short y = 0; y < CHUNKHEIGHT; y++)
		{
			if(blockList[x][y][0] == NULL || isAnySeeThrough(blockList[x][y]))
			{
				backgroundSprite->SetPosition((16*xPos-16 + x)*16, (16*yPos-16  + y)*16);
				app.Draw(*backgroundSprite);
			}
			for(int l = 5; l >= 0; l--)
			{
				if(blockList[x][y][l] != NULL)
				{
					blockList[x][y][l]->Draw(x, y, xPos, yPos, app, tc); 
					if(!blockList[x][y][l]->isSeeThrough())
						break;
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