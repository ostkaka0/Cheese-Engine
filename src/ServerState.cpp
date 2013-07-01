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
	std::queue<std::pair<MessageType, unsigned char*>>* packetDataList = currentWorld->Update(app, tC);
	while (!packetDataList->empty())
	{
		sf::Packet packet;

		packet << (sf::Int16)packetDataList->front().first;
		packet.Append(reinterpret_cast<void*>(packetDataList->front().second), sizeof(packetDataList->front().second));
		sC->Broadcast(packet);

		packetDataList->pop();
	}
	delete packetDataList;
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
		case PingMessage: //measure ping between sent 1 and received 1 (type)
			{
				float ping = client->pingClock.GetElapsedTime();
				client->pingClock.Reset();
				client->ping = ping;
				std::cout << "Client " << client->ID << " has ping " << ping << std::endl;
			}
			break;
		case KickMessage: //server kicks client (type, string message)

			break;
		case PlayerJoinLeft:
			{
				std::cout << "Received PlayerJoinLeft" << std::endl;
				sf::Int16 type;
				float xPos;
				float yPos;
				*packet >>  type >> xPos >> yPos;
				if(type == 0)
					currentWorld->AddPlayer(client->ID, new Player(xPos, yPos, 16, 16, true, "graywizard.png", 0, "temp"));
				else if(type == 1)
					currentWorld->RemovePlayer(client->ID);

				sf::Packet send;
				sf::Int16 packetType = PlayerJoinLeft;
				send << PlayerJoinLeft << type << xPos << yPos << client->ID;
				sC->Broadcast(send);
				break;
			}
		case PlayerMove:
			{
				short id;
				float xPos;
				float yPos;
				float speedX;
				float speedY;
				float angle;
				float horizontal;
				float vertical;
				*packet >> id >> xPos >> yPos >> speedX >> speedY >> angle >> horizontal >> vertical;
				Player* p = currentWorld->GetPlayer(id);
				p->CreatureMove(xPos, yPos, speedX, speedY, angle, horizontal, vertical);
				//Player* temp = new Player(xPos, yPos, 16, 16, true, "graywizard.png", 0, "temp");
				//temp->setSpeedX(speedX);
				//temp->setSpeedY(speedY);
				//temp->setAngle(angle);
				//currentWorld->SetPlayer(client->ID, temp);
				std::cout << "Moved player! :D" << std::endl;
			}
			break;
		}
		delete packet;
		packets.pop();
	}
}