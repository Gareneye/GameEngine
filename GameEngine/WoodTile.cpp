#include "WoodTile.h"



WoodTile::WoodTile()
{
	tileType = Type::WOOD;
	texture->loadFromFile("data/wood.png");
}


WoodTile::~WoodTile()
{
}

void WoodTile::update(float dt)
{
}