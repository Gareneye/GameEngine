#pragma once

#include <SFML/Graphics.hpp>
#include "Chunk.h"
#include "EngineResources.h"

class TexturedChunk :
	public sf::Drawable
{
public:
	TexturedChunk(int x, int y, const Chunk & chunk);
	~TexturedChunk();

	void render();
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;


private:
	sf::RectangleShape shape;
	sf::Texture texture;
	const Chunk & chunk;

	int x, y;
};

