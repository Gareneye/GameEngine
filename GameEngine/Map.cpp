#include "Map.h"

Map::Map()
{
	mapData.add(0, 0, chunkManager.loadChunk(0, 0));
	mapData.add(1, 0, chunkManager.loadChunk(1, 0));

	culling.setData(&mapData);
	culling.reset();
}


Map::~Map()
{
}

void Map::update(float)
{

}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(culling);
}

void Map::camera(const sf::FloatRect & camera)
{
	//culling(camera);
}
