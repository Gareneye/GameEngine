#include "MapData.h"



MapData::MapData()
{
}


MapData::~MapData()
{
}

const Chunk & MapData::getChunk(int x, int y)
{
	ChunkContainer & target = getDirection(x, y);
	Chunk * chunk = target[{abs(x), abs(y)}];

	if (chunk != nullptr)
		return *chunk;
	else
		return add(x, y, chunkManager.loadChunk(x, y));
}

inline ChunkContainer& MapData::getDirection(int x, int y)
{
	if (x < 0)
	{
		if (y < 0)
			return sw;
		else
			return nw;
	}
	else
	{
		if (y < 0)
			return se;
		else
			return ne;
	}

}

const Chunk & MapData::add(int x, int y, const Chunk & chunk)
{
	ChunkContainer & target = getDirection(x, y);

	// kopiowanie
	return *(target[{abs(x), abs(y)}] = new Chunk(chunk));
}