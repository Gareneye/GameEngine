#include "Chunk.h"

Chunk::Chunk() {
	for (int x = 0; x < CHUNK_SIZE; ++x)
		for (int y = 0; y < CHUNK_SIZE; ++y)
			data[x][y] = Tile::Type::NONE;
}

Chunk::Chunk(const Chunk & chunk)
{
	for (int x = 0; x < CHUNK_SIZE; ++x)
		for (int y = 0; y < CHUNK_SIZE; ++y)
			data[x][y] = chunk.data[x][y];
}

Chunk::~Chunk() {

}

Chunk::Chunk(const Tile::Type copy[CHUNK_SIZE][CHUNK_SIZE]) {
	for (int x = 0; x < CHUNK_SIZE; ++x)
		for (int y = 0; y < CHUNK_SIZE; ++y)
			data[x][y] = copy[x][y];
}

std::size_t Chunk::hash(int x, int y)
{
	return (
		std::hash<int>()(x) ^
		std::hash<int>()(y) << 1
		);
}
