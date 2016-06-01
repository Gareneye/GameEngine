#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <list>

#include "EngineResources.h"
#include "GameObject.h"
#include "Tile.h"
#include "WoodTile.h"
#include "Chunk.h"
#include "Logger.h"
#include "ChunkManager.h"



namespace {

	class MapArrays
	{
	public:
		void add(int x, int y, Chunk chunk)
		{
			int position = cantorHash(x, y);
			std::vector<Chunk>& target = direction(x, y);

			if (target.size() <= position)
				target.resize(position + 1);

			target.at(position) = chunk;
		}

		Chunk & get(int x, int y)
		{
			return direction(x, y).at(cantorHash(x, y));
		}

	private:
		std::vector<Chunk> nw;
		std::vector<Chunk> ne;
		std::vector<Chunk> se;
		std::vector<Chunk> sw;

		unsigned int cantorHash(int x, int y) const
		{
			x = abs(x);
			y = abs(y);

			return (x + y)*(x + y + 1) / 2 + y;
		}

		std::vector<Chunk> & direction(int x, int y)
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
	};

	struct Tiles
	{
		Tile noneTile;
		WoodTile woodTile;

	} TileObjects;

	class TexturedChunk {
	public:
		TexturedChunk(int x, int y, const Chunk & chunk) : x(x), y(y), chunk(chunk), shape({ CHUNK_SIZE*TILE_SIZE, CHUNK_SIZE*TILE_SIZE })
		{
			texture.create(CHUNK_SIZE*TILE_SIZE, CHUNK_SIZE*TILE_SIZE);

			shape.setPosition(x, y);
			shape.setTexture(&texture);

			render();
		}

		void render()
		{
			for (int i = 0; i < CHUNK_SIZE; ++i)
				for (int j = 0; j < CHUNK_SIZE; ++j)
				{
					Tile::Type type = chunk.get(i, j);
					const sf::Uint8 * pixels = nullptr;

					switch (type)
					{
					case Tile::WOOD:
						pixels = TileObjects.woodTile.getPixels();

					case Tile::NONE:
					default:
						continue;
						break;
					}

					texture.update(pixels, TILE_SIZE, TILE_SIZE, TILE_SIZE * i, TILE_SIZE * j);
				}
		}

		void draw(sf::RenderWindow & window) {
			window.draw(shape);
		}

	private:
		sf::RectangleShape shape;
		sf::Texture texture;
		const Chunk & chunk;

		int x, y;
	};

	class ChunkCulling
	{
	public:
		ChunkCulling()
		{
		}

		void reset()
		{
			visibleChunks.clear();
		}

		void operator()(MapArrays & mapArrays)
		{
			visibleChunks.emplace_back(0,0, mapArrays.get(0,0));
		}

		// todo typo on sf::drawable
		void draw(sf::RenderWindow & window) {
			for (auto chunk : visibleChunks)
			{
				chunk.draw(window);
			}
		}

	private:
		std::list<TexturedChunk> visibleChunks;
	};
}

class Map : public GameObject
{
public:
	Map();
	virtual ~Map();

	void update(float) override;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	//void setCamera(const sf::FloatRect &);

private:
	MapArrays mapData;
	ChunkManager chunkManager;
	ChunkCulling culling;

	// Camera Rectangle for Culling
	sf::FloatRect camera;

	TexturedChunk * test;
};

