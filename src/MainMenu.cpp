#include <iostream>
#include <vector>
#include "MainMenu.h"
#include "MenuState.h"
#include "GameState.h"

MainMenu::MainMenu() : MenuState()//void MainMenu::Initialize()
{

	lambda = [this]()
	{
		std::cout << "XD";
	};

 //   menuItems.push_back(new Label(13,37,16,16,lambda));
    std::cout << "TESTING" << std::endl;
}

MainMenu::~MainMenu()// : MenuState()//void MainMenu::Shutdown()
{
	MenuState::~MenuState();
}

void MainMenu::EventUpdate(sf::Event &event)
{
    MenuState::EventUpdate(event);
}

GameState *MainMenu::Update(sf::RenderWindow &app)
{
    MenuState::Update(app);
    return this;
}

void MainMenu::Draw(sf::RenderWindow &app)
{
    MenuState::Draw(app);
    //menuItems.
}


