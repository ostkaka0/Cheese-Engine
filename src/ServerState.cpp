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
	std::cout << "updates per second: " << 1/APP(app).GetFrameTime() << std::endl;
	currentWorld->Update(app, tC);
	return this;
}