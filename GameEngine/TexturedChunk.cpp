#include "TexturedChunk.h"



TexturedChunk::TexturedChunk(int x, int y, const Chunk & chunk)
	: x(x), y(y), 
	chunk(chunk), 
	shape({ CHUNK_SIZE*TILE_SIZE, CHUNK_SIZE*TILE_SIZE })
{
	texture.create(CHUNK_SIZE*TILE_SIZE, CHUNK_SIZE*TILE_SIZE);

	shape.setPosition(CHUNK_SIZE*TILE_SIZE*x, CHUNK_SIZE*TILE_SIZE*y);
	shape.setTexture(&texture);

	render();
}


TexturedChunk::~TexturedChunk()
{
}

void TexturedChunk::render()
{
	for (int i = 0; i < CHUNK_SIZE; ++i)
		for (int j = 0; j < CHUNK_SIZE; ++j)
		{
			Tile::Type type = chunk.get(i, j);
			const sf::Uint8 * pixels = nullptr;

			/*
			switch (type)
			{
			case Tile::WOOD:
				pixels = EngineResources::TileObjects.woodTile.getPixels();
				break;

			case Tile::NONE:
			default:
				continue;
				break;
			}
			*/

			pixels = EngineResources::TileObjects.woodTile.getPixels();

			texture.update(pixels, TILE_SIZE, TILE_SIZE, TILE_SIZE * i, TILE_SIZE * j);
		}
}

void TexturedChunk::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(shape);
}
