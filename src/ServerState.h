#pragma once
#include "gamestate.h"
#include "TextureContainer.h"
<<<<<<< HEAD

=======
#include "ServerConnection.h"
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d

class World;
class InGameUI;
class Camera;

class ServerState : public GameState
{
	World* currentWorld;
	TextureContainer tC;
<<<<<<< HEAD
=======
	ServerConnection* sC;
	void ProcessPackets();
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d
public:
	ServerState(App& app);
	~ServerState();
	virtual void EventUpdate(sf::Event& event) {}
    virtual GameState *Update(App& app);
	virtual void Draw(App& app) {}
};

