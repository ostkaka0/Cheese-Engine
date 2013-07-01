#ifndef _SERVER

#include <iostream>
#include <string>
#include <SFML\Network.hpp>
//#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "PlayState.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "World.h"
#include "Camera.h"
#include "InGameUI.h"
#include "Player.h"
#include "BlockSolid.h"
#include "BlockBackground.h"

namespace sf
{
	class RenderWindow;
}



PlayState::PlayState(App& app)
{
	camera = new Camera(32);
	currentWorld = new World();
	blockMenu = new InGameUI(tC, *currentWorld);
	connection = new Connection(5001, sf::IPAddress::GetLocalAddress());
	connection->Launch();

	app.SetView(*camera);
	camera->SetHalfSize(sf::Vector2f(768/2, 512/2)); 

	//Player* player = new Player(128, 128, 16, 16, true, "graywizard.png", 0, "Karl-Bertil");
	//currentWorld->AddPlayer(2,player); //MÅSTE FIXAS!!!!!!!!!!!!!
	//camera->setCameraAt(*player);

	//unsigned short i = 1;

	//currentWorld->RegisterBlock(i,(new BlockSolid(i))->RegisterBlock(i++));
	//+currentWorld->RegisterBlock(i,(new BlockBackground(i))->RegisterBlock(i++));
	//std::cin.get();

	//currentWorld->RegisterBlock(i,[&](unsigned short metadata) { return blockBackground; });
}

PlayState::~PlayState()
{
	//delete camera;
	//delete currentWorld;
	//delete blockMenu;
}

void PlayState::EventUpdate(sf::Event& event)
{

}

GameState *PlayState::Update(App& app)
{
	std::queue<sf::Packet>* packetDataList = currentWorld->Update(app, tC);
	while (!packetDataList->empty())
	{
		connection->client->socket.Send(packetDataList->front());
		packetDataList->pop();
	}
	//delete packetDataList;

	camera->Update(app);
	blockMenu->Update(app, tC, *currentWorld);
	ProcessPackets();
	return this;
}

void PlayState::Draw(App& app)
{
	currentWorld->Draw(app, tC);
	blockMenu->Draw(app, tC, *currentWorld);
}

void PlayState::ProcessPackets(void)
{
	connection->globalMutex.Lock();
	std::queue<sf::Packet*> packets = connection->packets;
	connection->packets = std::queue<sf::Packet*>();
	connection->globalMutex.Unlock();

	while(packets.size() > 0)
	{
		sf::Packet* packet = packets.front();
		//Now process packets
		sf::Int16 packetType;
		*packet >> packetType;

		switch(packetType)
		{
		case ClientID:
			{
				int ID;
				*packet >> ID;
				connection->client->ID = ID;
				std::cout << "My ID is now " << ID << std::endl;

				sf::Packet send;
				sf::Int16 packetType = PlayerJoinLeft;
				sf::Int16 type = 0;
				float speedX = 0;
				float speedY = 0;
				send << packetType << type << speedX << speedY;
				connection->client->socket.Send(send);
				std::cout << "Sent PlayerJoinLeft" << std::endl;
			}
			break;
		case PingMessage: //measure ping between sent 1 and received 1 (type)
			{
				/////////////////////////////////////
			}
			break;
		case KickMessage: //server kicks client (type, string message)

			break;
		case PlayerJoinLeft:
			std::cout << "Got PlayerJoinLeft" << std::endl;
			sf::Int16 type;
			float xPos;
			float yPos;
			int clientID;
			*packet >>  type >> xPos >> yPos >> clientID;
			if(type == 0)
			{
				Player* temp = new Player(xPos, yPos, 16, 16, false, "graywizard.png", 0, "temp");
				if(clientID == connection->client->ID)
				{
					temp->isClientControlling = true;
					std::cout << "Camera set" << std::endl;
					camera->setCameraAt(*temp);
				}
				currentWorld->AddPlayer(clientID, temp);
			}
			else if(type == 1)
				currentWorld->RemovePlayer(clientID);
			break;
		case PlayerMove:
			{
				float xPos;
				float yPos;
				float speedX;
				float speedY;
				float angle;
				*packet >> xPos >> yPos >> speedX >> speedY >> angle;
				//Player* temp = new Player(xPos, yPos, 16, 16, true, "graywizard.png", 0, "temp");
				//temp->setSpeedX(speedX);
				//temp->setSpeedY(speedY);
				//temp->setAngle(angle);
				//currentWorld->SetPlayer(client->ID, temp);
				std::cout << "Moved player! :D" << std::endl;
			}
			break;
			std::cout << packetType << std::endl;
		}
		delete packet;
		packets.pop();
	}
}
#endif