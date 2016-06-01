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

	Chunk loadChunk(int x, int y);
	void saveChunk(int x, int y, const Chunk &);
private:
	std::string path;
	std::string getPath(int x, int y);

	std::fstream fileStream;
};