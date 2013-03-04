#pragma once
#include "gamestate.h"
#include "World.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "TextureContainer.h"
#include "Camera.h"
#include "InGameUI.h"
#include "Projectile.h"

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

