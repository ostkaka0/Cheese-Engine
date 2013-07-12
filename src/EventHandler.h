#ifndef _SERVER
#pragma once

#include <map>
#include <functional>
#include <SFML\Graphics.hpp>

class App;

class EventHandler
{
	std::map<void*, std::function<void(sf::Event)>> callbackList;
public:
	void EventUpdate(sf::Event event);
	void AddEventCallback(void* source, std::function<void(sf::Event)> callback);
	void RemoveEventCallback(void* source);
};
#endif