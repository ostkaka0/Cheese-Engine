#ifndef _SERVER
#pragma once
#include "App.h"
#include "gamestate.h"
#include "TextureContainer.h"
<<<<<<< HEAD

=======
#include <SFML\Graphics.hpp>
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d

class World;
class InGameUI;
class Camera;

class PlayState : public GameState
{
	TextureContainer tC;
	Camera *camera;
	InGameUI *blockMenu;
public:
	PlayState(App& app);
	~PlayState();
    virtual void EventUpdate(sf::Event& event);
    virtual GameState *Update(App& app);
    virtual void Draw(App& app);
	World* currentWorld;
};
#endif
