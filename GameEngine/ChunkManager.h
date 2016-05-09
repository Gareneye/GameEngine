#pragma once

#include <string>
#include <sstream>
#include "Chunk.h"
#include "EngineResources.h"

class ChunkManager
{
public:
	ChunkManager();
	~ChunkManager();

	const Chunk & operator()(ChunkUtilities::Coords coords);
	const Chunk & operator()(int x, int y);

	void saveChunk(ChunkUtilities::Coords coords, Chunk);
private:
	std::string path;

	const Chunk & loadChunk(ChunkUtilities::Coords coords);
	std::string getPath(ChunkUtilities::Coords coords);

	std::fstream fileStream;
};