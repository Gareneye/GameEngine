#pragma once

#include "Settings.h"
#include "SettingsLoader.h"
#include "WoodTile.h"
#include "GrassTile.h"

namespace EngineResources
{
	extern Settings settings;

	extern struct Tiles
	{
		Tile noneTile;
		WoodTile woodTile;
		GrassTile grassTile;

	} TileObjects;
}