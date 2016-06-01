#include "Map.h"

Map::Map()
{
	mapData.add(0, 0, chunkManager.loadChunk(0, 0));
	//culling(mapData);

	test = new TexturedChunk(0, 0, mapData.get(0, 0));
}


Map::~Map()
{
}

void Map::update(float)
{

}

void Map::draw(sf::RenderWindow & window)
{
	test->draw(window);
	//culling.draw(window);
}
