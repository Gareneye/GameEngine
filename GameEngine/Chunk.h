#pragma once

#define CHUNK_SIZE 16
#define TILE_SIZE 30

#include <array>
#include "Tile.h"
#include "EngineResources.h"

class Chunk {

public:
	Chunk() : data{ Tile::NONE } {}

	Tile::Type get(unsigned int x, unsigned int y) const
	{
		return data[x][y];
	}

	void set(unsigned int x, unsigned int y, Tile::Type type)
	{
		data[x][y] = type;
	}

	static std::size_t hash(int x, int y)
	{
		
		return (
			std::hash<int>()(x) ^
			std::hash<int>()(y) << 1
			);
	}

private:
	Tile::Type data[CHUNK_SIZE][CHUNK_SIZE];
};
