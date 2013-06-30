#ifndef _SERVER

#include <iostream>
#include <string>
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

	app.SetView(*camera);
	camera->SetHalfSize(sf::Vector2f(768/2, 512/2)); 

	Player* player = new Player(128, 128, 16, 16, true, "graywizard.png", 0, "Karl-Bertil");
	currentWorld->AddPlayer(player);
	camera->setCameraAt(*player);

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
	currentWorld->Update(app, tC);
	camera->Update(app);
	blockMenu->Update(app, tC, *currentWorld);
	return this;
}

void PlayState::Draw(App& app)
{
	currentWorld->Draw(app, tC);
	blockMenu->Draw(app, tC, *currentWorld);
}
#endif