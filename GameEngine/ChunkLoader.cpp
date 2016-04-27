#include "ChunkLoader.h"



ChunkLoader::ChunkLoader() : path(EngineResources::settings["chunks_path"])
{}

ChunkLoader::~ChunkLoader()
{}

Chunk ChunkLoader::operator()(ChunkUtilities::Coords coords)
{
	return loadChunk(std::move(coords));
}

Chunk ChunkLoader::operator()(int x, int y)
{
	return loadChunk({x, y});
}

Chunk ChunkLoader::loadChunk(ChunkUtilities::Coords coords)
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

void ChunkLoader::saveChunk(ChunkUtilities::Coords coords, Chunk chunk)
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

std::string ChunkLoader::getName(ChunkUtilities::Coords coords)
{
	std::stringstream stringStream;
	ChunkUtilities::CoordsHash value;
	stringStream << value(coords);

	return stringStream.str();
}
