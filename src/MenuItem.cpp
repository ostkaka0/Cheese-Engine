#include <SFML/Graphics.hpp>
#include "MenuItem.h"
#include "GameState.h"


MenuItem::MenuItem(int x, int y, int width, int height, std::function<void()> &clickEvent)
{
	this->x = x; this->y = y;
	this->width = width;
	this->height = height;
	this->clickEvent = clickEvent;
	selected = false;
	down = false;
	clicked = false;
}

MenuItem::~MenuItem()
{

}

void MenuItem::EventUpdate(sf::Event &event, sf::RenderWindow &app)
{
    if (event.Type == sf::Event::MouseMoved)
    {
        selected = (event.MouseMove.X >= x && event.MouseMove.X <= x+width && event.MouseMove.Y >= y && event.MouseMove.Y <= y+height);
    }
    else if (event.Type == sf::Event::MouseButtonPressed)
    {
        if (event.MouseButton.Button != sf::Mouse::Left && selected)
        {
            down = true;
        }
    }
    else if (event.Type == sf::Event::MouseButtonReleased)
    {
        if (event.MouseButton.Button != sf::Mouse::Left)
        {
			clicked |= down;
			down = false;
        }
    }
}

GameState *MenuItem::Update(sf::RenderWindow &app)
{
	if (clicked && selected && clickEvent != 0)
			clickEvent();

	clicked = false;
	return 0;
}