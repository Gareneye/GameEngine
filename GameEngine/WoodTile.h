#pragma once

#include "Tile.h"

class WoodTile : public Tile
{
public:
	WoodTile();
	virtual ~WoodTile();

	virtual void update(float) override;
};

