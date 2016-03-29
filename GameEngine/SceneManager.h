#pragma once

#include <stack>
#include "SFML\Graphics.hpp"
#include "Scene.h"

class SceneManager
{
public:
	SceneManager(Scene *);
	virtual ~SceneManager();

	Scene * getScene();
	bool step();

private:
	std::stack<Scene *> scenes;

	void manageScenes();
};