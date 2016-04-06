#include "Map.h"



Map::Map()
{
	// size of tiles
	tileSize = std::stod(EngineResources::settings.get("tile_size"));

	//placeholder, chunk soon
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		mapArray[i][j] = Tiles::WOOD;
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

			window.draw(quad, getTexture(mapArray[i][j]));
		}

}

const sf::Texture * Map::getTexture(Tiles type)
{
	switch (type)
	{
	case Tiles::WOOD:
		return woodTile.getTexture();
		break;

	case Tiles::NONE:
	default:
		return noneTile.getTexture();
		break;
	}
}
