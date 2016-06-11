#pragma once

#include <vector>
#include <unordered_map>
#include <memory>

#include "Chunk.h"
#include "ChunkManager.h"

namespace {
	struct CantorHash {
		size_t operator() (const std::pair<unsigned int, unsigned int> & key) const
		{
			return (key.first + key.second)*(key.first + key.second + 1) / 2 + key.second;
		}
	};

	typedef std::unordered_map<std::pair<unsigned int, unsigned int>, Chunk *, CantorHash> ChunkContainer;
}

class MapData
{
public:
	MapData();
	~MapData();

	const Chunk & getChunk(int x, int y);

private:
	ChunkContainer nw;
	ChunkContainer ne;
	ChunkContainer se;
	ChunkContainer sw;

	// For import chunkes
	ChunkManager chunkManager;

	ChunkContainer & getDirection(int x, int y);

	Chunk loadChunk(int x, int y);
	const Chunk & add(int x, int y, const Chunk &);
};

