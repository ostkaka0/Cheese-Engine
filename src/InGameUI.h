#pragma once
#include <SFML\Graphics.hpp>
#include "TextureContainer.h"
#include "Camera.h"
#include "World.h"
#include "Block.h"

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

