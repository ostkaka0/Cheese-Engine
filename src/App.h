#pragma once

#ifdef _SERVER
#define APP(a) (*reinterpret_cast<App*>(&a))

#include <SFML\System.hpp>

class App
{
	sf::Clock frameTimer;
	float frameTime;
	float sleptTime;
public:
	float GetFrameTime();

	void Update();
	sf::Clock& getFrameTimer();
};
#else
#include <SFML\Graphics.hpp>
typedef sf::RenderWindow App;
#define APP(a) a
#endif