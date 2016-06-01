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
	void drag(sf::Vector2f);

	sf::FloatRect getViewport();

	//follow(const Unit &)

	// for window only
	const sf::View & getView() const;

private:
	sf::View view;
	sf::Vector2f posTarget;

	float speed;
	float distance;
	float radius;

	static const float PI;
};

