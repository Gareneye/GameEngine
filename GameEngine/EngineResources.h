#pragma once

#include "Settings.h"
#include "SettingsLoader.h"
#include "WoodTile.h"

namespace EngineResources
{
	extern Settings settings;

	extern struct Tiles
	{
		Tile noneTile;
		WoodTile woodTile;

	} TileObjects;
}