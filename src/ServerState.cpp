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
<<<<<<< HEAD

=======
	sC = new ServerConnection(5001);
	sC->Launch();
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
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
<<<<<<< HEAD
	std::cout << "updates per second: " << 1/APP(app).GetFrameTime() << std::endl;
	currentWorld->Update(app, tC);
	return this;
=======
	//std::cout << "updates per second: " << 1/APP(app).GetFrameTime() << std::endl;
	currentWorld->Update(app, tC);
	ProcessPackets();
	return this;
}

void ServerState::ProcessPackets(void)
{
	if(sC->packets.size() > 0)
	{
		sf::Packet* packet = sC->packets.front();
		sC->packets.pop();
		//delete(packet);
	}
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
}