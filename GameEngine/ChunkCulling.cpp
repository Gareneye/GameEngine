#include "ChunkCulling.h"



ChunkCulling::ChunkCulling(MapData & mapData) : mapData(mapData), chunkSizePixels(CHUNK_IN_PX), cullingBounds{0,0,0,0}
{
}


ChunkCulling::~ChunkCulling()
{
}

void ChunkCulling::update(float dt)
{
	for (auto &x : toDraw) {
		for (auto &y : x.second) {
			y.second.get()->update(dt);
		}
	}
}

void ChunkCulling::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto &x : toDraw) {
		for (auto &y : x.second) {
			target.draw(*y.second.get());
		}
	}
}


void ChunkCulling::operator()(const sf::FloatRect & camera)
{
	Bounds newBounds = {
		floor(camera.left / chunkSizePixels),
		floor(camera.top / chunkSizePixels),

		floor((camera.left + camera.width) / chunkSizePixels),
		floor((camera.top + camera.height) / chunkSizePixels)
	};

	if (newBounds == cullingBounds) return;

	int sharedStartX = std::max(newBounds.startX, cullingBounds.startX);
	int sharedEndX = std::min(newBounds.endX, cullingBounds.endX);

	//usuwanie poprzednich i nastepnych xow
	for (int i = cullingBounds.startX; i < sharedStartX; i++)
	{
		toDraw[i].clear();
	}

	for (int i = sharedEndX+1; i <= cullingBounds.endX; i++)
	{
		toDraw[i].clear();
	}

	int sharedStartY = std::max(newBounds.startY, cullingBounds.startY);
	int sharedEndY = std::min(newBounds.endY, cullingBounds.endY);

	//usuwanie poprzednich i nastepnych ykow
	for (int x = newBounds.startX; x <= newBounds.endX; x++)
	{
		for (int y = cullingBounds.startY; y < sharedStartY; y++)
			toDraw[x].erase(y);

		for (int y = sharedEndY + 1; y <= cullingBounds.endY; y++)
			toDraw[x].erase(y);

		for (int y = newBounds.startY; y <= newBounds.endY; y++)
		{
			if (!toDraw[x][y])
				toDraw[x][y] = std::make_unique<TexturedChunk>(x, y, mapData.getChunk(x, y));
		}
	}

	cullingBounds = newBounds;
}
