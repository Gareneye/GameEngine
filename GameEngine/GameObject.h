#pragma once

#include <SFML\Graphics.hpp>

struct GameObject
{
	virtual void update(float) = 0;
	virtual void draw(sf::RenderWindow &) = 0;
};