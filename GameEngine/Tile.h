#pragma once

#include <SFML\Graphics.hpp>

class Tile
{
public:
	Tile();
	virtual ~Tile();

	const sf::Texture * getTexture();

	// virtual void notify(Unit&, Event)
	virtual void update(float);

protected:
	sf::Texture * texture;
};

