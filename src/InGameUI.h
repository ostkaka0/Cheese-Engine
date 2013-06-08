class InGameUI;
#pragma once
#include <SFML\Graphics.hpp>

class TextureContainer;
class World;
class Camera;
class Block;

class InGameUI
{
public:
	InGameUI(TextureContainer &tc, World &world);
	~InGameUI(void);
	void Update(sf::RenderWindow &app, TextureContainer &tc, Camera &camera, World &world);
	void Draw(sf::RenderWindow &app, TextureContainer &tc, Camera &camera, World &world);
	std::map<Block*, sf::Vector2f> InGameUIItemList;
	short int selectedBlockSolid;
	short int selectedBackground;
};

