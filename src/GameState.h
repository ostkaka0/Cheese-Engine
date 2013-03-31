#pragma once

#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include <SFML/Graphics.hpp>

class GameState {
public:
    //virtual void Initialize()=0;
    virtual void EventUpdate(sf::Event &event)=0;
    virtual GameState *Update(sf::RenderWindow &app)=0;
    virtual void Draw(sf::RenderWindow &app)=0;
    //virtual void Shutdown()=0;
};

#endif // GAMESTATE_H_INCLUDED
