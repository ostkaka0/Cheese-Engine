#ifndef TEXTURECONTAINER_H_INCLUDED
#define TEXTURECONTAINER_H_INCLUDED
#define TEXTURETYPE_BLOCK 0
#define TEXTURETYPE_SMILEY 1

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