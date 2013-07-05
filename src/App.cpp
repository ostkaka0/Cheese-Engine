#ifdef _SERVER
#include "App.h"
#include <SFML\System.hpp>

#define MIN_FRAME_TIME 0.00390625F

<<<<<<< HEAD
#ifndef _SERVER
App::App(sf::VideoMode videoMode) : RenderWindow(videoMode, "Cheese Multiplayer - Alpha")
{

}
#endif

float App::getFrameTime()
=======
float App::GetFrameTime()
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82
{
	return frameTime+sleptTime;
}

void App::Update()
{
	frameTime = frameTimer.GetElapsedTime();

	if (frameTime < MIN_FRAME_TIME)
	{
		sleptTime = MIN_FRAME_TIME-frameTime;
		sf::Sleep(sleptTime);
	}
	else
	{
		sleptTime = 0;
	}

	frameTimer.Reset();
}

sf::Clock& App::getFrameTimer()
{
	return frameTimer;
}
#endif
