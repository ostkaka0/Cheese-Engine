#pragma once

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "MessageType.h"

struct Client
{
public:
	//Client(void);
	//~Client(void);
	sf::SocketTCP socket;
	sf::Uint16 ID;
	std::string name;
	sf::IPAddress IP;
	sf::Uint16 ping;
	sf::Clock pingClock;
};

