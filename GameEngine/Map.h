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
#include "TexturedChunk.h"

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
			int position = cantorHash(x, y);
			//todo sprawdzanie
			return direction(x, y).at(cantorHash(x, y));
		}

	private:
		// todo na wskazniki
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

	
	class ChunkCulling : public sf::Drawable
	{
	public:
		void setData(MapArrays * mapArray)
		{
			this->mapArray = mapArray;
		}

		void reset()
		{
			visibleChunks.clear();
			visibleChunks.emplace_back(0, 0, mapArray->get(0, 0));
			visibleChunks.emplace_back(1, 0, mapArray->get(1, 0));
			//visibleChunks.emplace_back(0, 1, mapArray->get(0, 1));
			//visibleChunks.emplace_back(0, 1, mapArray->get(1, 0));
			//visibleChunks.emplace_back(-1, 0, mapArray->get(1, 0));
		}

#include <iostream>
		void operator()(const sf::FloatRect & camera)
		{
			std::cout << camera.left << std::endl;
		}

		void draw(sf::RenderTarget & target, sf::RenderStates states) const override
		{
			for (auto chunk : visibleChunks)
			{
				target.draw(chunk);
			}
		}

	private:
		std::list<TexturedChunk> visibleChunks;
		MapArrays * mapArray;
	};
}

class Map : public GameObject
{
public:
	Map();
	virtual ~Map();

	void update(float) override;
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void camera(const sf::FloatRect &);

private:
	MapArrays mapData;
	ChunkManager chunkManager;
	ChunkCulling culling;
};

