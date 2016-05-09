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

void Tile::update(float) {}
