#include "World.h"
#define SIZEXMAX 256
#define SIZEYMAX 256

World::World(short unsigned sizeX, short unsigned sizeY)
{
	this->sizeX = sizeX+1;
	this->sizeY = sizeY+1;

	if(this->sizeX > SIZEXMAX)
		this->sizeX = SIZEXMAX;
	if(this->sizeY > SIZEYMAX)
		this->sizeY = SIZEYMAX;

	for(int x = 0; x < this->sizeX; x++)
	{
		for(int y = 0; y < this->sizeY; y++)
		{
			chunkList[x][y] = new Chunk();
		}
	}
}

World::~World(void)
{

}

void World::Draw(sf::RenderWindow &app, TextureContainer &tc, Player &player)
{
	/*sf::Sprite *borderSprite(&(tc.getTextures("BlockSolid.png")[0]));

	for(int bX = -1; bX < (sizeX * CHUNKWIDTH - 16) + 1; bX++)
	{
		for(int bY = -1; bY < (sizeY * CHUNKHEIGHT - 16) + 1; bY++)
		{
			borderSprite->SetPosition(bX * 16, bY * 16);
			app.Draw(*borderSprite);
		}
	}*/

	float playerX = player.getX();
	float playerY = player.getY();
 
	int chunkX = (playerX/16)/16;
	int chunkY = (playerY/16)/16;

	for(short x = -2; x < 4; x++)
	{
		for(short y = -2; y < 3; y++)
		{
			if(chunkX+x > 0 && chunkY+y > 0 && chunkX+x < sizeX && chunkY+y < sizeY)
			{
				chunkList[chunkX + x][chunkY + y]->Draw(chunkX + x, chunkY + y, app, tc);
				//std::cout << chunkX + x << " " << chunkY + y << std::endl;
			}
		}
	}
}

void World::setBlock(short x, short y, Block* block)
{
	int chunkX = (x/16)/16;
	int chunkY = (y/16)/16;
	int blockX = (x/16) % 16;
	int blockY = (y/16) % 16;
	if(chunkX*16 + blockX >= 0 && chunkX*16 + blockX < sizeX*16 && chunkY*16 + blockY>= 0 && chunkY*16 + blockY < sizeY*16)
	{
		std::cout << "xchunk: " << chunkX << " ychunk: " << chunkY << " xblock: " << blockX << " yblock: " << blockY << std::endl;
		chunkList[chunkX][chunkY]->setBlock(blockX, blockY, *block);
	}
}


Block* World::getBlock(short x, short y)
{
		int chunkX = (x/16)/16;
	int chunkY = (y/16)/16;
	int blockX = (x/16) % 16;
	int blockY = (y/16) % 16;
	return(chunkList[chunkX][chunkY]->getBlock(blockX, blockY));
}