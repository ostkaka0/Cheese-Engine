#pragma once

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <queue>
#include "Player.h"
#include "World.h"

#include "Client.h"

class Connection : public sf::Thread
{
public:
	Connection(int port, sf::IPAddress IP);
	~Connection(void);
	std::queue<sf::Packet*> packets;
	sf::Mutex globalMutex;
	Client* client;
private:
	bool Connect(sf::IPAddress ip, int port);
	virtual void Run();
	void Receive();
};

