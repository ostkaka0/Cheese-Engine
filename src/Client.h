#pragma once

#include <SFML/Network.hpp>
#include <SFML/System.hpp>

struct Client
{
public:
	//Client(void);
	//~Client(void);
	sf::SocketTCP socket;
	sf::Int16 ID;
	std::string name;
	sf::IPAddress IP;
	sf::Int16 ping;
	sf::Clock pingClock;
};

