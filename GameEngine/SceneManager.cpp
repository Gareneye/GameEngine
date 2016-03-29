#include "SceneManager.h"


SceneManager::SceneManager(Scene * scene)
{
	scenes.push(scene);
}

SceneManager::~SceneManager()
{
}

Scene * SceneManager::getScene()
{
	return this->scenes.top();
}

bool SceneManager::step()
{
	this->manageScenes();
	return !this->scenes.empty();
}

void SceneManager::manageScenes()
{
	Scene * active = this->scenes.top();

	switch (active->getState())
	{
	case Scene::SWITCH_NEXT:
		{
			this->scenes.push(active->getNext());
			active->setState(Scene::ON);
		}
		break;
	case Scene::OFF:
		{
			this->scenes.pop();
			delete active;
		}
		break;
	}
}
