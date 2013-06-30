<<<<<<< HEAD
class InGameUI;
#pragma once
#include <SFML\Graphics.hpp>
=======
#ifndef _SERVER
class InGameUI;
#pragma once
#include <SFML\Graphics.hpp>
#include "App.h"
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d

class TextureContainer;
class World;
class Camera;
class Block;

class InGameUI
{
public:
	InGameUI(TextureContainer &tc, World &world);
	~InGameUI(void);
	void Update(App& app, TextureContainer &tc, World &world);
	void Draw(App& app, TextureContainer &tc, World &world);
	std::map<Block*, sf::Vector2f> InGameUIItemList;
	short int selectedBlockSolid;
	short int selectedBackground;
};
#endif
