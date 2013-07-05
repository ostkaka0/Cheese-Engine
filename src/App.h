#pragma once

#ifdef _SERVER
<<<<<<< HEAD
#include <SFML\System.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

#define APP(a) (*reinterpret_cast<App*>(&a))

class App
#ifndef _SERVER
	: public sf::RenderWindow
#endif
=======
#define APP(a) (*reinterpret_cast<App*>(&a))

#include <SFML\System.hpp>

class App
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82
{
	sf::Clock frameTimer;
	float frameTime;
	float sleptTime;
public:
<<<<<<< HEAD
#ifndef _SERVER
	App(sf::VideoMode);
#endif
	float getFrameTime();
=======
	float GetFrameTime();
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82

	void Update();
	sf::Clock& getFrameTimer();
};
#else
#include <SFML\Graphics.hpp>
typedef sf::RenderWindow App;
#define APP(a) a
#endif
