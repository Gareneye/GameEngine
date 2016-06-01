#include "Tile.h"

Tile::Tile() : texture()
{
}


Tile::~Tile()
{
}

const sf::Image & Tile::getImage()
{
	return texture;
}

const sf::Uint8 * Tile::getPixels()
{
	return texture.getPixelsPtr();
}

void Tile::update(float) {}
