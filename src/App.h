#pragma once

//#ifdef _SERVER
#define APP(a) (*reinterpret_cast<App*>(&a))

#include <SFML\System.hpp>
#include <SFML/Graphics.hpp>

class App : public sf::RenderWindow
{
	sf::Clock frameTimer;
	float frameTime;
	float sleptTime;
public:
	App(sf::VideoMode);
	float getFrameTime();

	void Update();
	sf::Clock& getFrameTimer();
};
//#else
//#include <SFML\Graphics.hpp>
//typedef sf::RenderWindow App;
//#define APP(a) a
//#endif