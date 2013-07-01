#pragma once

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <queue>
#include "Client.h"

class ServerConnection : public sf::Thread
{
public:
	sf::Mutex globalMutex;
	ServerConnection(int port);
	~ServerConnection(void);
	std::queue<std::pair<sf::Packet*, Client*>> packets;
	void Broadcast(sf::Packet packet);
private:
	long int maxClients;
	virtual void Run();
	void KickClient(int ID, std::string reason);
	void PingClients();
	void Accept();
	void Receive();
	sf::SocketTCP s;
	std::map<int, Client*> clients;
	sf::IPAddress localIP;
	sf::IPAddress publicIP;
	sf::Clock pingTimeout;
};

