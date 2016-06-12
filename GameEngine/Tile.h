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
		WOOD,

		END // abstract Type for end random
	};

	const sf::Image & getImage();
	const sf::Uint8 * getPixels();

	// virtual void notify(Unit&, Event)
	virtual void update(float);

protected:
	Type tileType;
	sf::Image texture;
};

