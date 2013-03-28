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

	DrawBorder(2);
}

World::~World(void)
{

}

void World::DrawBorder(int blockId)
{
	for(int xx = 0; xx < this->sizeX * 16; xx++)
	{
		this->setBlock(2, 256 + xx * 16, 256, new BlockSolid(blockId));
		this->setBlock(2, 256 + xx * 16, sizeY * 16 * 16 - 16, new BlockSolid(blockId));
	}
	for(int yy = 0; yy < this->sizeY * 16; yy++)
	{
		this->setBlock(2, 256, 256 + yy * 16, new BlockSolid(blockId));
		this->setBlock(2, sizeX * 16 * 16 - 16, 256 + yy * 16, new BlockSolid(blockId));
	}
}

void World::Update(sf::RenderWindow& app, Camera &camera)
{
	for (std::vector<Projectile*>::size_type i = 0; i < projectileList.size(); i++)
	{
		projectileList[i]->Update(app, camera);
	}
	for (std::vector<Player*>::size_type i = 0; i < playerList.size(); i++)
	{
		playerList[i]->Update(app, camera);
	}
}

void World::Draw(sf::RenderWindow& app, TextureContainer& tc, Camera &camera)
{
	float playerX = camera.getEntityPosition().x;
	float playerY = camera.getEntityPosition().y;

	int chunkX = (int)((playerX/16)/16);
	int chunkY = (int)((playerY/16)/16);

	for(short x = -2; x < 4; x++)
	{
		for(short y = -2; y < 4; y++)
		{
			if(chunkX+x > 0 && chunkY+y > 0 && chunkX+x < sizeX && chunkY+y < sizeY)
			{
				chunkList[chunkX + x][chunkY + y]->Draw(chunkX + x, chunkY + y, app, tc, camera);
			}
		}
	}

	//Projectile start
	/*if(app.GetInput().IsMouseButtonDown(sf::Mouse::Left))
	{
		double angle = atan2((camera.GetCenter().y + app.GetInput().GetMouseY() - 256) - (camera.getCreaturePosition().y+8), (camera.GetCenter().x + app.GetInput().GetMouseX() - 384) - (camera.getCreaturePosition().x+8)) * 180 / 3.1415;
		if (angle < 0)
			angle = angle + 360;
		projectileList.push_back(new Projectile(sf::Vector2f(camera.getCreaturePosition().x+8, camera.getCreaturePosition().y+8), (float)angle, 500, tc.getTextures("arrowb.png")[0]));
	}*/

	for (std::vector<Projectile>::size_type i = 0; i < projectileList.size(); i++)
	{
		if(isVisible(app, camera, projectileList[i]->getPosition().x, projectileList[i]->getPosition().y, projectileList[i]->getSize().x, projectileList[i]->getSize().y))
		{
			projectileList[i]->Draw(app);
		}
	}

	//Player start
	for (std::vector<Player*>::size_type i = 0; i < playerList.size(); i++)
	{
		if(isVisible(app, camera, playerList[i]->getPosition().x, playerList[i]->getPosition().y, playerList[i]->getSize().x, playerList[i]->getSize().y))
		{
			playerList[i]->Draw(app, tc);
		}
	}
}

void World::setBlock(unsigned char layer, short x, short y, Block* block)
{
	int chunkX = (x/16)/16;
	int chunkY = (y/16)/16;
	int blockX = (x/16) % 16;
	int blockY = (y/16) % 16;
	if(chunkX*16 + blockX >= 0 && chunkX*16 + blockX < sizeX*16 && chunkY*16 + blockY>= 0 && chunkY*16 + blockY < sizeY*16)
	{
		//std::cout << "xchunk: " << chunkX << " ychunk: " << chunkY << " xblock: " << blockX << " yblock: " << blockY << std::endl;
		chunkList[chunkX][chunkY]->setBlock(layer, blockX, blockY, *block);
	}
}


Block* World::getBlock(unsigned char layer, short x, short y)
{
	int chunkX = (x/16)/16;
	int chunkY = (y/16)/16;
	int blockX = (x/16) % 16;
	int blockY = (y/16) % 16;
	if(chunkX*16 + blockX >= 0 && chunkX*16 + blockX < sizeX*16 && chunkY*16 + blockY>= 0 && chunkY*16 + blockY < sizeY*16)
	{
		return(chunkList[chunkX][chunkY]->getBlock(layer, blockX, blockY));
	}
	else
	{
		return(NULL);
	}
}

void World::AddBlockType(unsigned short key, std::function<Block*(unsigned short)> value)
{
	blockTypeMap.emplace(key, value);
}

std::function<Block*(unsigned short)>* World::getBlockType(unsigned short id)
{
	auto it = blockTypeMap.find(id);
	return (it == blockTypeMap.end()) ? NULL : &it->second;
}

std::map<unsigned short, std::function<Block*(unsigned short)>>* World::getBlockTypeMap()
{
	return &blockTypeMap;
}

sf::Vector2i World::getSize(){return(sf::Vector2i(sizeX, sizeY));};

bool World::isVisible(sf::RenderWindow& app, Camera& camera, float posX, float posY, float sizeX, float sizeY)
{
	if((posX + sizeX) >= (camera.GetCenter().x - camera.GetHalfSize().x))
	{
		if((posY + sizeY) >= (camera.GetCenter().y - camera.GetHalfSize().y))
		{
			if(posX <= (camera.GetCenter().x + camera.GetHalfSize().x) && posY <= (camera.GetCenter().y + camera.GetHalfSize().y))
			{
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

void World::AddCreature(Creature* creature)
{
	creatureList.push_back(creature);
}

void World::AddPlayer(Player* player, short Id)
{
	playerList.insert((playerList.begin() + Id), player);
}

void World::RemovePlayer(short Id)
{
	playerList.erase(playerList.begin() + Id);
}