#pragma once

#include "SFML\Graphics.hpp"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void update(float) = 0;
	virtual void draw(sf::RenderWindow &) = 0;
	virtual void inputs(sf::Event) = 0;
};

