#pragma once

#include "Scene.h"
#include "GameScene.h"

struct SceneInitializer
{
	enum Scenes
	{
		GAME_SCENE,
		MENU_SCENE
	};

	static Scene * get(Scenes id)
	{
		switch (id)
		{
		case GAME_SCENE:
			return new GameScene();
			break;
		case MENU_SCENE:
			//return new MenuScene();
			break;
		}

		return new NullScene();
	}
};