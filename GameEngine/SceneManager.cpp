#include "SceneManager.h"

SceneManager::SceneManager() : active(nullptr), status(ON)
{
}

SceneManager::~SceneManager()
{
	delete active;
	active = nullptr;
}

Scene & SceneManager::getScene()
{
	return *active;
}

void SceneManager::setScene(const SceneInitializer::Scenes & scene)
{
	delete active;
	active = SceneInitializer::get(scene);
}

bool SceneManager::step()
{
	return status;
}

void SceneManager::finish()
{
	status = OFF;
}
