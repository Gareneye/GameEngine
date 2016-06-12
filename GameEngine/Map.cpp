#include "Map.h"

Map::Map() : culling(mapData)
{
}


Map::~Map()
{
}

void Map::update(float dt)
{
	culling.update(dt);
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(culling);
}

void Map::camera(const sf::FloatRect & camera)
{
	culling(camera);
}

void Map::debugCulling(bool change)
{
	culling.toggleEnable(!change);
}
