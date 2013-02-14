#include <string>
#include "GameState.h"
#include "PlayState.h"
using namespace sf;



PlayState::PlayState(sf::RenderWindow *window)
{
	camera = new Camera(10);
	currentWorld = new World(8, 8);
	blockMenu = new InGameUI(tc, *currentWorld);

	window->SetView(*camera);
	camera->SetHalfSize(sf::Vector2f(768/2, 512/2)); 

	player = new Player(0, 0, true, "graywizard.png", 0, "Karl-Bertil");

	BlockSolid blockSolid(0);
	BlockBackground blockBackground(0);

	currentWorld->AddBlockType(blockSolid.getId(),[](unsigned short metadata) { return new BlockSolid(metadata); });
	//currentWorld->AddBlockType(blockBackground.getId(),[](unsigned short metadata) { return new BlockBackground(metadata); });
}

PlayState::~PlayState()
{
	
}

void PlayState::EventUpdate(sf::Event &event)
{

}

GameState *PlayState::Update(sf::RenderWindow &app)
{
	player->Update(app, *camera);

	if(app.GetInput().IsMouseButtonDown(sf::Mouse::Left))
	{
		currentWorld->setBlock(2, camera->GetCenter().x + app.GetInput().GetMouseX()-(8*16), camera->GetCenter().y + app.GetInput().GetMouseY(), new BlockSolid(15));
	}
	else if(app.GetInput().IsMouseButtonDown(sf::Mouse::Right))
	{
		currentWorld->setBlock(2, camera->GetCenter().x + app.GetInput().GetMouseX()-(8*16), camera->GetCenter().y + app.GetInput().GetMouseY(), NULL);	
	}
	//std::cout << "Chunk x: " << (int)((player->getX()/16)/16) << " y: " << (int)((player->getY()/16)/16) << std::endl;
	camera->Update(app);
	blockMenu->Update(app, tc, *camera, *currentWorld);
	return this;
}

void PlayState::Draw(sf::RenderWindow &app)
{
	currentWorld->Draw(app, tc, *player);
	player->Draw(app, tc);
	blockMenu->Draw(app, tc, *camera, *currentWorld);
	//std::cout << "FPS: " << (1/app.GetFrameTime()) << std::endl;
}

void PlayState::AddCreature(Creature* creature)
{
	creatureList.push_back(creature);
}

void PlayState::AddPlayer(Player* player)
{
	playerList.push_back(player);
}
