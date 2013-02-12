#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MainMenu.h"
#include "GameState.h"

Menu::Menu()//void Menu::Initialize()
{
    menuState = new MainMenu();
    //menuState->Initialize();
}

Menu::~Menu()//void Menu::Shutdown()
{
    //menuState->Shutdown();
    delete menuState;
}

void Menu::EventUpdate(sf::Event &event)
{
    menuState->EventUpdate(event);
}

GameState *Menu::Update(sf::RenderWindow &app)
{
	GameState *newState = menuState->Update(app);
	if (newState != menuState)
    {
		if (dynamic_cast<MenuState*>(newState) != 0)
		{
			return newState;
		}
		else
		{
			//menuState->Shutdown();
			delete menuState;
			menuState = newState;
			//menuState->Initialize();
		}
    }
    return this;
}

void Menu::Draw(sf::RenderWindow &app)
{
    menuState->Draw(app);
}
