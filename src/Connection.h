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
	void Run();
private:
<<<<<<< HEAD
	//sf::Thread* thread;
	bool Connect(sf::IpAddress ip, int port);
=======
	bool Connect(sf::IPAddress ip, int port);
	virtual void Run();
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82
	void Receive();
};

