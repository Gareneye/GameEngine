#include "Tile.h"

Tile::Tile() : texture(new sf::Image())
{
}


Tile::~Tile()
{
}

const sf::Uint8 * Tile::getPixels()
{
	return texture->getPixelsPtr();
}

void Tile::update(float) {}
