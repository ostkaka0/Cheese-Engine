#include "App.h"

#ifndef _SERVER
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "PlayState.h"
#else
#include "ServerState.h"

#endif

int _argc;
char** _argv;
//using namespace sf;

/*#ifdef _SERVER
<<<<<<< HEAD
#define _APP *reinterpret_cast<tgui::Window*>(&app)//static_cast<tgui::Window>(app)
=======
	#define _APP *reinterpret_cast<sf::RenderWindow*>(&app)//static_cast<sf::RenderWindow>(app)
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82
#else
#define _APP app
#endif*/

int main(int argc, char** argv)
{
	_argc = argc;
	_argv = argv;

#ifndef _SERVER
<<<<<<< HEAD

	App app(sf::VideoMode(768, 512));

	GameState *gameState = new PlayState((const PlayState&)app);
#else
	App app;
=======
    App app(sf::VideoMode(768, 512), "Cheese Multiplayer - Alpha");
	GameState *gameState = new PlayState(app);
#else
	App app;//App app();
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82
	GameState *gameState = new ServerState(app);
#endif

	GameState *oldState;

	//app.SetFramerateLimit(6);
#ifndef _SERVER
<<<<<<< HEAD
	while (app.isOpen())
	{
		sf::Event event;
		if (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				app.close();

			gameState->EventUpdate(event);
		}
=======
	while (app.IsOpened())
    {
       sf::Event event;
       if (app.GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                app.Close();

            gameState->EventUpdate(event);
        }
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82
#else
	while (true)
	{
#endif

		oldState = gameState;
		if((gameState=gameState->Update(app)) != oldState)
		{
			delete oldState;
		}

#ifndef _SERVER
<<<<<<< HEAD
		app.clear();
=======
        app.Clear();
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82

		gameState->Draw(app);

<<<<<<< HEAD
		app.display();
=======
        app.Display();
>>>>>>> 3e2d1d23fd7a70df773ec0d22345bb1ca4eedc82
#else
		app.Update();
#endif
	}

	return 0;
}