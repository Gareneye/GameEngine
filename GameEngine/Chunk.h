#pragma once

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

class Chunk
{
public:
	Chunk();
	~Chunk();

	Tile::Type data[10][10];
};

