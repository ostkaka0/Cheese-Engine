<<<<<<< HEAD
class Camera;
#pragma once
#include <SFML/Graphics.hpp>
=======
#ifndef _SERVER
#pragma once
#include <SFML\Graphics.hpp>
#include "App.h"
>>>>>>> 7a55cfd848be568878e4143aa9b86f7d0468e19d

class Entity;

class Camera : public sf::View
{
private:
	Entity *currentEntity;
	double speed;
public:
	Camera(double speed);
	~Camera(void);
	void Update(App& app);
	void setCameraAt(Entity &entity);
	void setSpeed(double speed);
	sf::Vector2f getEntityPosition();
	Entity &Camera::getEntity();
};

inline Camera& GetCamera(App& app)
{
	return (*const_cast<Camera*>(reinterpret_cast<const Camera*>(&app.GetView())));
}
#endif

//#define GetCamera(app) (*const_cast<Camera*>(reinterpret_cast<const Camera*>(&app.GetView())))
