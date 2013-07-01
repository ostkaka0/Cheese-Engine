#pragma once
#include "gamestate.h"
#include "TextureContainer.h"
#include "ServerConnection.h"
#include "MessageType.h"
#include "Player.h"

class World;
class InGameUI;
class Camera;

class ServerState : public GameState
{
	World* currentWorld;
	TextureContainer tC;
	ServerConnection* sC;
	void ProcessPackets();
public:
	ServerState(App& app);
	~ServerState();
	virtual void EventUpdate(sf::Event& event) {}
    virtual GameState *Update(App& app);
	virtual void Draw(App& app) {}
};
