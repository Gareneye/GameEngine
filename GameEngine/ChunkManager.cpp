#include "ChunkManager.h"



ChunkManager::ChunkManager() : path(EngineResources::settings["chunks_path"])
{}

ChunkManager::~ChunkManager()
{}

Chunk ChunkManager::loadChunk(int x, int y)
{
	fileStream.open(getPath(std::move(x), std::move(y)), std::ios::in | std::ios::binary);

	if (!fileStream.is_open())
	{
		return generateChunk(x, y);
	}

	Chunk loadedChunk;
	fileStream.read((char*)&loadedChunk, sizeof(Chunk));
	fileStream.close();

	return loadedChunk;
}

void ChunkManager::saveChunk(int x, int y, const Chunk & chunk)
{
	fileStream.open(getPath(std::move(x), std::move(y)), std::ios::out | std::ios::binary | std::ios::trunc);

	fileStream.write((char*)&chunk, sizeof(Chunk));

	fileStream.close();
}

inline std::string ChunkManager::getPath(int x, int y)
{
	std::stringstream stringStream;
	stringStream << path << '/' << Chunk::hash(x, y) << ".chunk";
	return stringStream.str();
}

inline Chunk ChunkManager::generateChunk(int x, int y)
{
	Chunk chunk = chunkGenerator();
	saveChunk(x, y, chunk);
	return chunk;
}
