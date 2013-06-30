#include <iostream>
#include <string>
#include "ServerState.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "World.h"
#include "BlockSolid.h"
#include "BlockBackground.h"
#include "App.h"
#include <SFML\Graphics.hpp>



ServerState::ServerState(App& app)
{
	currentWorld = new World();
	sC = new ServerConnection(5001);
	sC->Launch();
	//unsigned short i = 1;

	//currentWorld->RegisterBlock(i,(new BlockSolid(i))->RegisterBlock(i++));
	//currentWorld->RegisterBlock(i,(new BlockBackground(i))->RegisterBlock(i++));
}

ServerState::~ServerState()
{
	delete currentWorld;
}

GameState *ServerState::Update(App& app)
{
	//std::cout << "updates per second: " << 1/APP(app).GetFrameTime() << std::endl;
	currentWorld->Update(app, tC);
	ProcessPackets();
	return this;
}

void ServerState::ProcessPackets(void)
{
	sC->globalMutex.Lock();
	auto packets = sC->packets;
	sC->packets = std::queue<std::pair<sf::Packet*, Client*>>();
	sC->globalMutex.Unlock();

	while(packets.size() > 0)
	{
		auto data = packets.front();
		sf::Packet* packet = data.first;
		Client* client = data.second;
		//Now process packets
		sf::Int16 packetType;
		*packet >> packetType;

		switch(packetType)
		{
		case 1: //measure ping between sent 1 and received 1 (type)
			{
				float ping = client->pingClock.GetElapsedTime();
				client->pingClock.Reset();
				client->ping = ping;
				std::cout << "Client " << client->ID << " has ping " << ping << std::endl;
			}
			break;
		case 2: //server kicks client (type, string message)

			break;
		}
		delete packet;
		packets.pop();
	}
}