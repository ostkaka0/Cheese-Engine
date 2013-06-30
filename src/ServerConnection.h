#pragma once

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <queue>
class ServerConnection : public sf::Thread
{
public:
	ServerConnection(int port);
	~ServerConnection(void);
	std::queue<sf::Packet*> packets;
private:
	long int maxClients;
	virtual void Run();
	void KickClient(int ID, std::string reason);
	void PingClients();
	void Accept();
	void Receive();
	sf::SocketTCP s;
	std::map<int, sf::SocketTCP> clients;
	sf::IPAddress localIP;
	sf::IPAddress publicIP;
	sf::Clock pingTimeout;
};

