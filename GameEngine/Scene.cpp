#include "Scene.h"



Scene::Scene() : next(nullptr), state(Scene::ON)
{
}

Scene::~Scene()
{
}

Scene::State Scene::getState()
{
	return this->state;
}

void Scene::setState(Scene::State state)
{
	this->state = state;
}

Scene * Scene::getNext()
{
	return this->next;
}

void Scene::turnNext(Scene * next)
{
	this->next = next;
	this->state = Scene::SWITCH_NEXT;
}

void Scene::turnOff()
{
	this->state = Scene::OFF;
}
