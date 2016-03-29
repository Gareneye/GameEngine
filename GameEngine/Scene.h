#pragma once

#include "SFML\Graphics.hpp"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void update(float) = 0;
	virtual void draw(sf::RenderWindow &) const = 0;
	virtual void inputs(sf::Event) = 0;
	
	enum State
	{
		OFF,
		ON,
		SWITCH_NEXT
	};
	State getState();
	void setState(State);
	Scene * getNext();

protected:
	void turnNext(Scene * next);
	void turnOff();

private:
	State state;
	Scene * next;
};

