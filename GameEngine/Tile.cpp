#include "Tile.h"

Tile::Tile() : texture(new sf::Texture())
{
}


Tile::~Tile()
{
}

const sf::Texture * Tile::getTexture()
{
	return texture;
}

void Tile::update(float) {}
