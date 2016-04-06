#include "GameScene.h"
#include "RootEngine.h"

GameScene::GameScene() : map()
{
}


GameScene::~GameScene()
{
}

void GameScene::update(float dt)
{
	map.update(dt);
}

void GameScene::draw(sf::RenderWindow & window)
{
	map.draw(window);
}

void GameScene::inputs(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		RootEngine::sceneManager.finish();
}
