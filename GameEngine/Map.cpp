#include "Map.h"

Map::Map()
{
	// size of tiles
	tileSize = std::stod(EngineResources::settings["tile_size"]);

	testChunkTexture = new sf::Texture();
	testChunkTexture->create(CHUNK_SIZE*tileSize, CHUNK_SIZE*tileSize);

	testChunkShape.setPosition(0, 0);
	testChunkShape.setSize(sf::Vector2f(800, 600));
	testChunkShape.setTexture(testChunkTexture);
	testWoodImage = new sf::Image();
	testWoodImage->loadFromFile("data/wood.png");

	//test
	ChunkManager chunkLoader;

	//placeholder, chunk soon
	/*
	Chunk tryChunk;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		tryChunk.data[i][j] = Tile::WOOD;
	*/

	mapArray[ChunkUtilities::Coords{ 0, 0 }].chunk = chunkLoader({ 0, 0 });
	
	/*
	chunkLoader.saveChunk({ 0, 0 }, tryChunk);
	chunkLoader({ 0, 0 });
	*/

	
	for (int i = 0; i < CHUNK_SIZE; ++i)
		for (int j = 0; j < CHUNK_SIZE; ++j)
		{
			Tile::Type type = mapArray[{ 0, 0 }].chunk.data[i][j];

			if (type == Tile::NONE)
				continue;

			testChunkTexture->update(*testWoodImage, tileSize * i, tileSize * j);
		}
		

	//testChunkTexture->update(*testWoodImage, tileSize, tileSize);
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
	window.draw(testChunkShape);

}

const sf::Uint8 * Map::getTexture(Tile::Type type)
{
	switch (type)
	{
	case Tile::WOOD:
		return woodTile.getPixels();
		break;

	case Tile::NONE:
	default:
		return noneTile.getPixels();
		break;
	}
}
