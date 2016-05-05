#pragma once

#define CHUNK_SIZE 64
#define TILE_SIZE 30

#include <array>
#include "Tile.h"
#include "EngineResources.h"

namespace ChunkUtilities
{
	struct Coords {
		int x; int y;
		bool operator==(const ChunkUtilities::Coords & compareWith) const
		{
			return (
				this->x == compareWith.x &&
				this->y == compareWith.y
				);
		}
	};

	struct CoordsHash
	{
		std::size_t operator()(const ChunkUtilities::Coords & coords) const
		{
			return (
				std::hash<int>()(coords.x) ^
				std::hash<int>()(coords.y) << 1
				);
		}
	};
}

struct Chunk
{
	Tile::Type data[CHUNK_SIZE][CHUNK_SIZE];
};

