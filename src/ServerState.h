#pragma once
#include "gamestate.h"
#include "TextureContainer.h"


class World;
class InGameUI;
class Camera;

class ServerState : public GameState
{
	World* currentWorld;
	TextureContainer tC;
public:
	ServerState(App& app);
	~ServerState();
	virtual void EventUpdate(sf::Event& event) {}
    virtual GameState *Update(App& app);
	virtual void Draw(App& app) {}
};

