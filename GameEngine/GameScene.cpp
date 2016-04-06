#include "GameScene.h"
#include "RootEngine.h"

GameScene::GameScene() : map(), camera()
{
}


GameScene::~GameScene()
{
}

void GameScene::update(float dt)
{
	camera.update(dt);
	map.update(dt);
}

void GameScene::draw(sf::RenderWindow & window)
{
	window.setView(camera.getView());
	map.draw(window);
}

#include <iostream>
void GameScene::inputs(sf::Event event, const sf::RenderWindow & window)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		RootEngine::sceneManager.finish();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2f mouse = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		camera.move(mouse);
	}

}
