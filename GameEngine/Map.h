#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "EngineResources.h"
#include "GameObject.h"
#include "Tile.h"
#include "WoodTile.h"
#include "Chunk.h"
#include "Logger.h"
#include "ChunkManager.h"

namespace {
	struct TexturedChunk {
		Chunk chunk;
		sf::Texture * texture;

		void clearTexture()
		{
			delete texture;
		}

		void createTexture()
		{
			texture = new sf::Texture();
			texture->create(CHUNK_SIZE*TILE_SIZE, CHUNK_SIZE*TILE_SIZE);

		}

		void renderTexture()
		{
			for (int i = 0; i < CHUNK_SIZE; ++i)
				for (int j = 0; j < CHUNK_SIZE; ++j)
				{
					Tile::Type type = chunk.data[i][j];

					if (type == Tile::NONE)
						continue;

					//texture->update(*testWoodImage, tileSize * i, tileSize * j);
				}
		}


	};

	typedef std::unordered_map<ChunkUtilities::Coords, TexturedChunk, ChunkUtilities::CoordsHash> MapArray;
}

class Map : public GameObject
{
public:
	Map();
	virtual ~Map();

	virtual void update(float) override;
	virtual void draw(sf::RenderWindow &) override;

	//void setCamera(const sf::FloatRect &);

protected:
	const sf::Uint8 * Map::getTexture(Tile::Type type);

private:
	MapArray mapArray;

	// Camera Rectangle for Culling
	sf::FloatRect camera;

	// Tile size
	float tileSize;

	sf::Texture * testChunkTexture;
	sf::RectangleShape testChunkShape;
	sf::Image * testWoodImage;

	// TILES
	Tile noneTile;
	WoodTile woodTile;
};

