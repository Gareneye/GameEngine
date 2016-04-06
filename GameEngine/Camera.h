#pragma once

#include "SFML\Graphics.hpp"
#include "EngineResources.h"

class Camera
{
public:
	Camera();
	virtual ~Camera();

	virtual void update(float);
	void move(sf::Vector2f);
	sf::FloatRect getViewport();

	// for window only
	const sf::View & getView();

private:
	sf::View view;
	sf::Vector2f posTarget;
	float maxSpeed;

	static const float PI;
};

