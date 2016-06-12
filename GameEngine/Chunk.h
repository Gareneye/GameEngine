#pragma once

#define CHUNK_SIZE 16
#define TILE_SIZE 30

#include <array>
#include "Tile.h"
#include "EngineResources.h"

class Chunk 
{
public:
	Chunk();
	Chunk(const Chunk &);
	~Chunk();

	Chunk(const Tile::Type copy[CHUNK_SIZE][CHUNK_SIZE]);

	Tile::Type get(unsigned int x, unsigned int y) const
	{
		return data[x][y];
	}

	void set(unsigned int x, unsigned int y, Tile::Type type)
	{
		data[x][y] = type;
	}

	static std::size_t hash(int x, int y);

private:
	Tile::Type data[CHUNK_SIZE][CHUNK_SIZE];
};
