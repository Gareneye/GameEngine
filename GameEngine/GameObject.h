#pragma once

#include <SFML\Graphics.hpp>

struct GameObject : sf::Drawable
{
	virtual void update(float) = 0;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const = 0;
};