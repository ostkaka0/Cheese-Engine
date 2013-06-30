#pragma once
#include <iostream>
<<<<<<< HEAD
#include <SFML/Graphics.hpp>

class TextureContainer;
=======
#include <functional>
#include "App.h" //#include <SFML/Graphics.hpp>

class TextureContainer;
class World;
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d

class Block
{
private:
	unsigned short id;
public:
<<<<<<< HEAD
	Block();
	unsigned char getMetadata();
	void setMetadata(unsigned char);
    virtual unsigned short getId()=0;
	virtual unsigned char getTextureId()=0;
=======
	Block(unsigned short id);

	unsigned short getId();

	virtual std::function<Block*(unsigned short)> RegisterBlock(const unsigned short id);
	virtual unsigned char getTextureId(App &app, unsigned short metadata)=0;
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
	virtual unsigned char getLayer()=0;
	virtual std::string getTextureName()=0;
	virtual bool isSeeThrough()=0;
	virtual bool isSolid()=0;
	virtual bool isSimple();
	//virtual char getSubTextureId() = 0;
<<<<<<< HEAD
	void Draw(short posX, short posY, sf::RenderWindow &app, TextureContainer &tc);
=======
#ifndef _SERVER
	void Draw(int posX, int posY, App& app, TextureContainer &tc, unsigned short metadata);
#endif
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
};