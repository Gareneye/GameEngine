#pragma once

#include "SFML\Graphics.hpp"
#include "Scene.h"
#include "SceneInitializer.h"

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	Scene & getScene();
	void setScene(const SceneInitializer::Scenes &);
	bool step();
	void finish();

private:
	Scene * active;

	enum {
		OFF,
		ON
	} status;
};