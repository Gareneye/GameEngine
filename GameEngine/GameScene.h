#pragma once

#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	virtual void update(float) override;
	virtual void draw(sf::RenderWindow &) override;
	virtual void inputs(sf::Event) override;
};

