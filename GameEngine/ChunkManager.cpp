#include "ChunkManager.h"



ChunkManager::ChunkManager() : path(EngineResources::settings["chunks_path"])
{}

ChunkManager::~ChunkManager()
{}

Chunk ChunkManager::loadChunk(int x, int y)
{
	std::string path = getPath(std::move(x), std::move(y));
	fileStream.open(path, std::ios::in | std::ios::binary);

	std::cout << "Ladowanie chunka x " << x << " y " << y << std::endl;

	if (!fileStream.is_open())
	{
		std::cout << "Nie znaleziono chunka x " << x << " y " << y << std::endl;
		Logger::log("Nie mozna otworzyc chunka " + path);
		// TODO GENERATOR
		saveChunk(x, y, Chunk());
		return Chunk();
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
