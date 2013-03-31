#pragma once

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "GameState.h"
#include "MenuState.h"

class Menu : public GameState
{
private:
    GameState *menuState;
public:
	Menu();
	~Menu();
    //virtual void Initialize();
    virtual void EventUpdate(sf::Event &event);
    virtual GameState *Update(sf::RenderWindow &app);
    virtual void Draw(sf::RenderWindow &app);
    //virtual void Shutdown();
};

#endif // MENU_H_INCLUDED
