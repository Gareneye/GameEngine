#pragma once

#include <SFML/Graphics.hpp>
#include <queue>
#include "Chunk.h"
#include "EngineResources.h"
#include "GameObject.h"

#define CHUNK_IN_PX CHUNK_SIZE*TILE_SIZE

class TexturedChunk :
	public GameObject
{
public:
	TexturedChunk(int x, int y, const Chunk & chunk);
	TexturedChunk(const TexturedChunk &);
	~TexturedChunk();

	void render();
	void render(int x, int y, Tile::Type tile);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void update(float) override;

	void notify(int x, int y, Tile::Type tile);
	bool isVisible(const sf::FloatRect &) const;

private:
	sf::RectangleShape shape;
	sf::Texture * texture;

	const Chunk & chunk;

	int x, y;

	// kolejka zmian
	struct ChangedTile {
		int x;
		int y;
		Tile::Type tile;
	};

	std::queue<ChangedTile> changes;

#if _DEBUG 
	sf::Font font;
	sf::Text text;
#endif //  _DEBUG

};

