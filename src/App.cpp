#ifdef _SERVER
#include "App.h"
#include <SFML\System.hpp>

#define MIN_FRAME_TIME 0.00390625F

float App::GetFrameTime()
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