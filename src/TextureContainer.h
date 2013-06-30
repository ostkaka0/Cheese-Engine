<<<<<<< HEAD
=======
#pragma once

>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
class TextureContainer;
#ifndef TEXTURECONTAINER_H_INCLUDED
#define TEXTURECONTAINER_H_INCLUDED

#include <map>
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>

class TextureContainer
{
private:
	std::map<std::string, sf::Sprite*> textureList;
public:
	TextureContainer(void);
	~TextureContainer(void);
	bool AddTexture(std::string fileName, int textureType);
	bool AddSpriteSheet(std::string fileName, int spriteWidth, int spriteHeight);
	sf::Sprite* getTextures(std::string textureName);
};

#endif