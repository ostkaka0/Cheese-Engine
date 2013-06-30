#include "App.h"

#ifndef _SERVER
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
<<<<<<< HEAD
#include "GameState.h"
#include "PlayState.h"
//using namespace sf;
=======
#include "PlayState.h"
#else
#include "ServerState.h"

#endif
//using namespace sf;

/*#ifdef _SERVER
	#define _APP *reinterpret_cast<sf::RenderWindow*>(&app)//static_cast<sf::RenderWindow>(app)
#else
	#define _APP app
#endif*/
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d

int main()
{
	
#ifndef _SERVER
    App app(sf::VideoMode(768, 512), "Cheese Multiplayer - Alpha");
	GameState *gameState = new PlayState(app);
#else
	App app;//App app();
	GameState *gameState = new ServerState(app);
#endif
	
	GameState *oldState;

	//app.SetFramerateLimit(6);
#ifndef _SERVER
	while (app.IsOpened())
    {
       sf::Event event;
       if (app.GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                app.Close();

            gameState->EventUpdate(event);
        }
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
        app.Clear();

        gameState->Draw(app);

        app.Display();
#else
		app.Update();
#endif
    }

    return 0;
}
