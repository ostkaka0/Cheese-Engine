#pragma once
#include "gamestate.h"
#include "TextureContainer.h"


class World;
class InGameUI;
class Camera;

class PlayState : public GameState
{
public:
	PlayState(sf::RenderWindow *window);
	~PlayState();
    virtual void EventUpdate(sf::Event &event);
    virtual GameState *Update(sf::RenderWindow &app);
    virtual void Draw(sf::RenderWindow &app);
	World* currentWorld;
	sf::Image playerImage;
	sf::Sprite* playerSprite;
	sf::Sprite *spriteList;
	TextureContainer tc;
	Camera *camera;
	InGameUI *blockMenu;
};

