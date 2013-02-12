#include <SFML\Graphics.hpp>
#include "MenuItem.h"
#include "Label.h"
#include "GameState.h"


Label::Label(int x, int y, int width, int height, std::function<void()> &clickEvent) : MenuItem(x, y, width, height, clickEvent)
{

}


Label::~Label()
{

}

void Label::EventUpdate(sf::Event &event, sf::RenderWindow &app)
{
	MenuItem::EventUpdate(event, app);
}

GameState *Label::Update(sf::RenderWindow &app)
{
	MenuItem::Update(app);
	return 0;
}

void Label::Draw(sf::RenderWindow &app)
{

}