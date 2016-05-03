#include "ChunkManager.h"



ChunkManager::ChunkManager() : path(EngineResources::settings["chunks_path"])
{}

ChunkManager::~ChunkManager()
{}

Chunk ChunkManager::operator()(ChunkUtilities::Coords coords)
{
	return loadChunk(std::move(coords));
}

Chunk ChunkManager::operator()(int x, int y)
{
	return loadChunk({x, y});
}

Chunk ChunkManager::loadChunk(ChunkUtilities::Coords coords)
{
	std::string filePath = path + "/" + getName(coords) + ".chunk";

	std::fstream chunkFile;
	chunkFile.open(filePath, std::ios::in | std::ios::binary);

	if (!chunkFile.is_open())
	{
		// TODO EXCEPTION
		Logger::log("Nie mozna otworzyc" + filePath);
		return Chunk();
	}

	Chunk loadedChunk;
	chunkFile.read((char*)&loadedChunk, sizeof(Chunk));
	chunkFile.close();

	return loadedChunk;
}

void ChunkManager::saveChunk(ChunkUtilities::Coords coords, Chunk chunk)
{
	std::string filePath = path + "/" + getName(coords) + ".chunk";

	std::fstream chunkFile;
	chunkFile.open(filePath, std::ios::out | std::ios::binary | std::ios::trunc);

	if (!chunkFile.is_open())
	{
		// TODO EXCEPTION
		Logger::log("Nie mozna otworzyc" + filePath);
	}

	chunkFile.write((char*)&chunk, sizeof(Chunk));
	chunkFile.close();
}

std::string ChunkManager::getName(ChunkUtilities::Coords coords)
{
	std::stringstream stringStream;
	ChunkUtilities::CoordsHash value;
	stringStream << value(coords);

	return stringStream.str();
}
