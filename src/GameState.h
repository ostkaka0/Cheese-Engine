<<<<<<< HEAD
class GameState;
=======
#pragma once

class GameState;

#include <SFML\Graphics.hpp>
#include "App.h"

>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

//#include <SFML/Graphics.hpp>

class GameState {
public:
    //virtual void Initialize()=0;
    virtual GameState *Update(App& app)=0;
#ifndef _SERVER
	virtual void EventUpdate(sf::Event& event)=0;
    virtual void Draw(App& app)=0;
#endif
    //virtual void Shutdown()=0;
};

#endif // GAMESTATE_H_INCLUDED
