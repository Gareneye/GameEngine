#pragma once

#include <vector>
#include <map>
#include <memory>

#include "GameObject.h"
#include "MapData.h"
#include "TexturedChunk.h"
#include "Chunk.h"

namespace {
	typedef std::map<int, std::map<int, std::unique_ptr<TexturedChunk>>> NestedMapOfChunk;
}

class ChunkCulling :
	public GameObject
{
public:
	ChunkCulling(MapData &);
	~ChunkCulling();


	void update(float) override;
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void operator()(const sf::FloatRect & camera);

private:
	MapData & mapData;

	struct Bounds {
		int startX;
		int startY;

		int endX;
		int endY;
	} cullingBounds;

	NestedMapOfChunk toDraw;

	// TODO GLOBAL OFFSET TO MINIMALIZE MEMORY POOL
	int offsetMemory;

	const unsigned int chunkSizePixels;
};

