#pragma once

#include "Scene.h"
#include "SFML\Graphics.hpp"

class Game : public Scene
{
public:
	Game();
	virtual ~Game();

	virtual void update(float) override;
	virtual void draw(sf::RenderWindow &) const override;
	virtual void inputs(sf::Event) override;
};

