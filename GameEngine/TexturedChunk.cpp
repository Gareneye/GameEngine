#include "TexturedChunk.h"

#include <iostream>

TexturedChunk::TexturedChunk(int x, int y, const Chunk & chunk)	: 
	x(x), y(y), 
	chunk(chunk), 
	shape({ CHUNK_IN_PX, CHUNK_IN_PX })
{
	texture = new sf::Texture();
	texture->create(CHUNK_IN_PX, CHUNK_IN_PX);

	shape.setPosition(CHUNK_IN_PX*x, CHUNK_IN_PX*y);
	shape.setTexture(texture);

	render();


#if _DEBUG 
	font.loadFromFile("data/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Regular);

	std::string chunkText = "Chunk " + std::to_string(x) + " " + std::to_string(y);

	text.setString(chunkText);
	text.setPosition(CHUNK_IN_PX*x + CHUNK_IN_PX/2, CHUNK_IN_PX*y + CHUNK_IN_PX / 2);

	std::cout << "Tworze chunka (" << x << ", " << y << ") " << std::endl;
#endif //  _DEBUG
}

TexturedChunk::TexturedChunk(const TexturedChunk & from) : 
	x(from.x), y(from.y),
	chunk(from.chunk),
	shape({ CHUNK_IN_PX, CHUNK_IN_PX })
{
	texture = new sf::Texture();
	*texture = *from.texture;

	shape.setPosition(CHUNK_IN_PX*from.x, CHUNK_IN_PX*from.y);
	shape.setTexture(texture);
}



TexturedChunk::~TexturedChunk()
{
	delete texture;

#if _DEBUG 
	std::cout << "Usuwam chunka (" << x << ", " << y << ") " << std::endl;
#endif //  _DEBUG
}

void TexturedChunk::render()
{
	while (!changes.empty())
		changes.pop();

	for (int i = 0; i < CHUNK_SIZE; ++i)
		for (int j = 0; j < CHUNK_SIZE; ++j)
			render(i, j, chunk.get(i, j));
}

void TexturedChunk::render(int x, int y, Tile::Type type)
{
	const sf::Uint8 * pixels = nullptr;

	switch (type)
	{
	case Tile::WOOD:
		pixels = EngineResources::TileObjects.woodTile.getPixels();
		break;

	case Tile::NONE:
	default:
		pixels = EngineResources::TileObjects.woodTile.getPixels();
		break;
	}

	texture->update(pixels, TILE_SIZE, TILE_SIZE, TILE_SIZE * x, TILE_SIZE * y);
}

void TexturedChunk::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(shape);

#if _DEBUG 
	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(x*CHUNK_IN_PX, y*CHUNK_IN_PX)),
		sf::Vertex(sf::Vector2f(x*CHUNK_IN_PX + CHUNK_IN_PX, y*CHUNK_IN_PX)),
	};
	target.draw(line1, 2, sf::Lines);

	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(x*CHUNK_IN_PX, y*CHUNK_IN_PX)),
		sf::Vertex(sf::Vector2f(x*CHUNK_IN_PX, y*CHUNK_IN_PX + CHUNK_IN_PX)),
	};
	target.draw(line2, 2, sf::Lines);
	target.draw(text);

#endif //  _DEBUG
}

void TexturedChunk::update(float)
{
	while (!changes.empty())
	{
		ChangedTile tile = changes.front();
		render(tile.x, tile.y, tile.tile);
		changes.pop();
	}
}

void TexturedChunk::notify(int x, int y, Tile::Type tile)
{
	changes.push({ std::move(x), std::move(y), std::move(tile) });
}

bool TexturedChunk::isVisible(const sf::FloatRect & camera) const
{
	const sf::FloatRect & chunk = shape.getGlobalBounds();

	return
		// Czy chunk zawiera sie w srodku kamery
		camera.contains(x, y) ||
		camera.contains(x + CHUNK_IN_PX, y) ||
		camera.contains(x, y + CHUNK_IN_PX) ||
		camera.contains(x + CHUNK_IN_PX, y + CHUNK_IN_PX) ||

		// Czy kamera zawiera sie w srodku chunka
		chunk.contains(camera.left, camera.top) ||
		chunk.contains(camera.left + camera.width, camera.top) ||
		chunk.contains(camera.left, camera.top + camera.height) ||
		chunk.contains(camera.left + camera.width, camera.top + camera.height);
}
