#pragma once

#include "Scene.h"
#include "Map.h"
#include "Camera.h"

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	virtual void update(float) override;
	virtual void draw(sf::RenderWindow &) override;
	virtual void inputs(sf::Event, const sf::RenderWindow &) override;

private:
	Map map;
	Camera camera;
};

