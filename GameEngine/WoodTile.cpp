#include "WoodTile.h"



WoodTile::WoodTile()
{
	tileType = Type::WOOD;
	texture->loadFromFile("data/wood.png");
	texture->setRepeated(true);
}


WoodTile::~WoodTile()
{
}

void WoodTile::update(float dt)
{
}