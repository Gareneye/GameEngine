#include "SceneManager.h"


SceneManager::SceneManager() : active(nullptr)
{
}

SceneManager::~SceneManager()
{
}

Scene & SceneManager::getScene()
{
	return *active;
}

void SceneManager::setScene(SceneInitializer::Scenes scene)
{
	delete active;
	active = SceneInitializer::get(scene);
}

bool SceneManager::step()
{
	return active;
}

void SceneManager::finish()
{
	delete active;
	active = nullptr;
}
