#include "Game.h"


#include <iostream>
Game::Game()
{
	std::cout << "WELCOME" << this << std::endl;
}


Game::~Game()
{
	std::cout << "BYE BYE" << this << std::endl;
}


void Game::update(float)
{
	std::cout << this << std::endl;
}

void Game::draw(sf::RenderWindow &) const
{
}

void Game::inputs(sf::Event event)
{
	if (event.type == sf::Event::Closed ||
		event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		turnOff();

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
		turnNext(new Game());
}
