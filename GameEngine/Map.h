#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>

#include "EngineResources.h"
#include "GameObject.h"
#include "Tile.h"
#include "WoodTile.h"
#include "Chunk.h"
#include "Logger.h"
#include "ChunkManager.h"
#include "TexturedChunk.h"
#include "MapData.h"
#include "ChunkCulling.h"

namespace {
}

class Map : public GameObject
{
public:
	Map();
	virtual ~Map();

	void update(float) override;
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void camera(const sf::FloatRect &);

private:
	MapData mapData;
	ChunkCulling culling;
};

