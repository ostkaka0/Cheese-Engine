class World;
#pragma once

#include <functional>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <SFML\Graphics.hpp>
 
class Chunk;
class Block;
class Entity;
class Player;
class TextureContainer;
class Camera;

#define SIZEXMAX 256
#define SIZEYMAX 256

#define SCREENSIZEX 800
#define SCREENSIZEY 600

class World
{
private:
	short int sizeX;
	short int sizeY;
	Chunk *chunkList[256][256];
	std::map<unsigned short, std::function<Block*(unsigned short)>> blockTypeMap;
	std::vector<Entity*> entityList;
	std::vector<Player*> playerList;

public:
	World(unsigned short, unsigned short);
	~World(void);
	void Draw(sf::RenderWindow& app, TextureContainer& tc, Camera &camera);
	void Update(sf::RenderWindow& app, Camera &camera);
	void setBlock(unsigned char layer, short x, short y, Block* block);
	void AddBlockType(unsigned short, std::function<Block*(unsigned short)>);
	void DrawBorder(int blockId);
	bool isVisible(sf::RenderWindow& app, Camera& camera, Entity& entity, short position);
	sf::Vector2i getSize();
	Block* getBlock(unsigned char layer, short x, short y);
	std::function<Block*(unsigned short)>* getBlockType(unsigned short id);
	std::map<unsigned short, std::function<Block*(unsigned short)>>* getBlockTypeMap();
	void AddEntity(Entity*);
	void AddPlayer(Player*, short Id);
	void RemovePlayer(short Id);
};