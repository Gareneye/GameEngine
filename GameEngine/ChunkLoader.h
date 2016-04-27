#pragma once

#include <string>
#include <sstream>
#include "Chunk.h"
#include "EngineResources.h"

class ChunkLoader
{
public:
	ChunkLoader();
	~ChunkLoader();

	Chunk operator()(ChunkUtilities::Coords coords);
	Chunk operator()(int x, int y);

	void saveChunk(ChunkUtilities::Coords coords, Chunk);
private:
	std::string path;

	Chunk loadChunk(ChunkUtilities::Coords coords);

	std::string getName(ChunkUtilities::Coords coords);
};