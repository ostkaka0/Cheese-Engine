#ifndef _SERVER
#include "EventHandler.h"
#include "App.h"

void EventHandler::EventUpdate(sf::Event event)
{
	for (auto it : callbackList)
	{
		it.second(event);
	}
}

void EventHandler::AddEventCallback(void* source, std::function<void(sf::Event)> callback)
{
	callbackList.emplace(source, callback);
}

void EventHandler::RemoveEventCallback(void* source)
{
	auto it = callbackList.find(source);
	if (it != callbackList.end())
	{
		callbackList.erase(it);
	}
}
#endif