#include "GameScene.h"
#include "RootEngine.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::update(float dt)
{
	camera.update(dt);
	//map.camera(camera.getViewport());
	map.update(dt);
}


void GameScene::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.setView(camera.getView());
	target.draw(map);
}

void GameScene::inputs(sf::Event event, const sf::RenderWindow & window)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		RootEngine::sceneManager.finish();

	if (event.type == sf::Event::KeyPressed)
	{
		const float distance = 200.0f;

		switch (event.key.code)
		{
		case sf::Keyboard::A:
			camera.drag(sf::Vector2f(-distance, .0f));
			break;
		case sf::Keyboard::W:
			camera.drag(sf::Vector2f(.0f, -distance));
			break;
		case sf::Keyboard::S:
			camera.drag(sf::Vector2f(.0f, distance));
			break;
		case sf::Keyboard::D:
			camera.drag(sf::Vector2f(distance, .0f));
			break;
		}

	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Middle)
		{
			camera.move( window.mapPixelToCoords(sf::Mouse::getPosition(window)) );
		}
	} 

}
