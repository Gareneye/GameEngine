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
#include "ChunkLoader.h"

namespace {
	typedef std::unordered_map<ChunkUtilities::Coords, Chunk, ChunkUtilities::CoordsHash> MapArray;
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
	const sf::Texture * Map::getTexture(Tile::Type type);

private:
	MapArray mapArray;

	// Camera Rectangle for Culling
	sf::FloatRect camera;

	// Tile size
	float tileSize;

	// TILES
	Tile noneTile;
	WoodTile woodTile;
};

