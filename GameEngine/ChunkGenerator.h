#pragma once

#include "Chunk.h"

class ChunkGenerator
{
public:
	ChunkGenerator();
	~ChunkGenerator();

	// todo perlin noise
	Chunk operator()();

	//todo set biom, random, whatever
};

