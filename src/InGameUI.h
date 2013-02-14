#pragma once
#include <SFML\Graphics.hpp>
#include "TextureContainer.h"
#include "Camera.h"
#include "World.h"

class InGameUI
{
public:
	InGameUI(TextureContainer &tc);
	~InGameUI(void);
	void Update(sf::RenderWindow &app, TextureContainer &tc, Camera &camera, World &world);
	void Draw(sf::RenderWindow &app, TextureContainer &tc, Camera &camera, World &world);
	std::map<sf::Sprite*, sf::Vector2f> InGameUIItemList;
};

