#pragma once

#include "SFML\Graphics.hpp"

struct Scene
{
	virtual void update(float) = 0;
	virtual void draw(sf::RenderWindow &) = 0;
	virtual void inputs(sf::Event, const sf::RenderWindow &) = 0;
};

