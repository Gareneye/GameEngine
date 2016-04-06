#pragma once

#include <vector>
#include <string>

#include "EngineResources.h"
#include "GameObject.h"
#include "Tile.h"
#include "WoodTile.h"

namespace {
	enum Tiles
	{
		NONE,
		WOOD
	};

	typedef Tiles MapArray[10][10];
}

class Map : public GameObject
{
public:
	Map();
	virtual ~Map();

	virtual void update(float) override;
	virtual void draw(sf::RenderWindow &) override;

	//void setCamera(const sf::FloatRect &);

protected:
	const sf::Texture * getTexture(Tiles);

private:
	MapArray mapArray;

	// Camera Rectangle
	sf::FloatRect camera;

	// Tile size
	float tileSize;

	// TILES
	Tile noneTile;
	WoodTile woodTile;
};

