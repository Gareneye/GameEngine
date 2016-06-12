#include "GrassTile.h"



GrassTile::GrassTile()
{
	tileType = Type::GRASS;
	texture.loadFromFile("data/grass.png");
}


GrassTile::~GrassTile()
{
}

void GrassTile::update(float)
{
}
