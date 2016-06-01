#pragma once

#include "SFML\Graphics.hpp"

struct Scene : sf::Drawable
{
	virtual void update(float) = 0;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const = 0;
	virtual void inputs(sf::Event, const sf::RenderWindow &) = 0;
};

struct NullScene final : public Scene {
	void update(float) override {};
	void inputs(sf::Event, const sf::RenderWindow &) override {};
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override {};
};