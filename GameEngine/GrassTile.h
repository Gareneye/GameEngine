#pragma once
#include "Tile.h"
class GrassTile :
	public Tile
{
public:
	GrassTile();
	~GrassTile();

	virtual void update(float) override;
};

