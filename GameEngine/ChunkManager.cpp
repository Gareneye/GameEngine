#include "ChunkManager.h"



ChunkManager::ChunkManager() : path(EngineResources::settings["chunks_path"])
{}

ChunkManager::~ChunkManager()
{}

const Chunk & ChunkManager::operator()(ChunkUtilities::Coords coords)
{
	return loadChunk(std::move(coords));
}

const Chunk & ChunkManager::operator()(int x, int y)
{
	return loadChunk({x, y});
}

const Chunk & ChunkManager::loadChunk(ChunkUtilities::Coords coords)
{
	fileStream.open(getPath(std::move(coords)), std::ios::in | std::ios::binary);

	if (!fileStream.is_open())
	{
		// TODO EXCEPTION
		Logger::log("Nie mozna otworzyc chunka");
		return Chunk();
	}

	Chunk loadedChunk;
	fileStream.read((char*)&loadedChunk, sizeof(Chunk));
	fileStream.close();

	return loadedChunk;
}

void ChunkManager::saveChunk(ChunkUtilities::Coords coords, Chunk chunk)
{
	fileStream.open(getPath(std::move(coords)), std::ios::out | std::ios::binary | std::ios::trunc);

	fileStream.write((char*)&chunk, sizeof(Chunk));

	fileStream.close();
}

std::string ChunkManager::getPath(ChunkUtilities::Coords coords)
{
	std::stringstream stringStream;
	ChunkUtilities::CoordsHash value;

	stringStream << path << '/' << value(coords) << ".chunk";

	return stringStream.str();
}
