#include "ChunkGenerator.h"



ChunkGenerator::ChunkGenerator()
{
}


ChunkGenerator::~ChunkGenerator()
{
}

Chunk ChunkGenerator::operator()()
{
	Tile::Type data[CHUNK_SIZE][CHUNK_SIZE];

	for (int x = 0; x < CHUNK_SIZE; ++x)
		for (int y = 0; y < CHUNK_SIZE; ++y)
			data[x][y] = static_cast<Tile::Type>(std::rand() % Tile::Type::END);

	return Chunk(data);
}
