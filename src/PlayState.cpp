#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>
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

using namespace sf;



PlayState::PlayState(sf::RenderWindow *window)
{
	camera = new Camera(8);
	currentWorld = new World(8, 8);
	blockMenu = new InGameUI(tc, *currentWorld);

	window->SetView(*camera);
	camera->SetHalfSize(sf::Vector2f(768/2, 512/2)); 

	Player* player = new Player(0, 0, 32, 32, true, "graywizard.png", 0, "Karl-Bertil");
	currentWorld->AddPlayer(player, 0);
	camera->setCameraAt(*player);

	BlockSolid blockSolid(0);
	BlockBackground blockBackground(0);

	currentWorld->AddBlockType(blockSolid.getId(),[](unsigned short metadata) { return new BlockSolid(metadata); });
	currentWorld->AddBlockType(blockBackground.getId(),[](unsigned short metadata) { return new BlockBackground(metadata); });
}

PlayState::~PlayState()
{

}

void PlayState::EventUpdate(sf::Event &event)
{

}

GameState *PlayState::Update(sf::RenderWindow &app)
{
	currentWorld->Update(app, *camera);
	camera->Update(app);
	blockMenu->Update(app, tc, *camera, *currentWorld);
	return this;
}

void PlayState::Draw(sf::RenderWindow &app)
{
	currentWorld->Draw(app, tc, *camera);
	blockMenu->Draw(app, tc, *camera, *currentWorld);
	std::cout << "FPS: " << (1/app.GetFrameTime()) << std::endl;
}
