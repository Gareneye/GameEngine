#pragma once

#include "SFML\Graphics.hpp"
#include "EngineResources.h"

class Camera
{
public:
	Camera();
	virtual ~Camera();

	virtual void update(float);
	void move(const sf::Vector2f &);
	void drag(const sf::Vector2f &);


	//follow(const Unit &)

	const sf::View & getView() const;
	const sf::FloatRect getViewport() const;
	void reset();

private:
	sf::View view;
	sf::Vector2f posTarget;

	float speed;
	float distance;
	float radius;

	static const float PI;
};

