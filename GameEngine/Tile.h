#pragma once

#include <SFML\Graphics.hpp>


class Tile
{
public:
	Tile();
	virtual ~Tile();

	// For goddness of clarity!
	enum Type
	{
		NONE,
		WOOD
	};

	const sf::Texture * getTexture();

	// virtual void notify(Unit&, Event)
	virtual void update(float);

protected:
	Type tileType;
	sf::Texture * texture;
};

