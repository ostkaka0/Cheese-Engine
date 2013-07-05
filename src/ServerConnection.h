#pragma once

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <queue>
#include "Client.h"
#include "World.h"

class ServerConnection : public sf::Thread
{
public:
	ServerConnection(int port, World* world);
	~ServerConnection(void);
	void Broadcast(sf::Packet packet);
	void KickClient(int ID, std::string reason);
	virtual void Run();

	sf::Mutex globalMutex;
	std::queue<std::pair<sf::Packet*, Client*>> packets;
	long int maxClients;
	std::map<int, Client*> clients;
private:
	void PingClients();
	void Accept();
	void Receive();
	sf::SocketTCP s;
	sf::IPAddress localIP;
	sf::IPAddress publicIP;
	sf::Clock pingTimeout;
	World* currentWorld;
};

