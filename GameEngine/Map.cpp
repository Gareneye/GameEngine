#include "Map.h"

Map::Map()
{
	// size of tiles
	tileSize = std::stod(EngineResources::settings["tile_size"]);

	//test
	ChunkLoader chunkLoader;

	//placeholder, chunk soon
	/*
	Chunk tryChunk;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		tryChunk.data[i][j] = Tile::WOOD;
	*/

	mapArray[ChunkUtilities::Coords{ 0, 0 }] = chunkLoader({ 0, 0 });
	
	/*
	chunkLoader.saveChunk({ 0, 0 }, tryChunk);
	chunkLoader({ 0, 0 });
	*/
}


Map::~Map()
{
}

void Map::update(float)
{
	// todo: queue of last updated tiles ex. [0][2]
}

void Map::draw(sf::RenderWindow & window)
{
	//todo: where is camera?

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		{
			sf::VertexArray quad(sf::Quads, 4);

			quad[0].position = sf::Vector2f(tileSize * i,		tileSize * j);
			quad[1].position = sf::Vector2f(tileSize * (i+1),	tileSize * j);
			quad[2].position = sf::Vector2f(tileSize * (i + 1), tileSize * (j + 1));
			quad[3].position = sf::Vector2f(tileSize * i,		tileSize * (j+1));

			quad[0].texCoords = sf::Vector2f(0, 0);
			quad[1].texCoords = sf::Vector2f(tileSize, 0);
			quad[2].texCoords = sf::Vector2f(tileSize, tileSize);
			quad[3].texCoords = sf::Vector2f(0, tileSize);

			window.draw(quad, getTexture(mapArray[{ 0, 0 }].data[i][j]));
		}

}

const sf::Texture * Map::getTexture(Tile::Type type)
{
	switch (type)
	{
	case Tile::WOOD:
		return woodTile.getTexture();
		break;

	case Tile::NONE:
	default:
		return noneTile.getTexture();
		break;
	}
}
