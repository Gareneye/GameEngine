#include "SFML\Graphics.hpp"

#include "RootEngine.h"
#include "EngineResources.h"

int main()
{
	// RootEngine
	RootEngine::sceneManager.setScene(SceneInitializer::GAME_SCENE);

	// Main Window
	sf::RenderWindow window(sf::VideoMode(600, 700), EngineResources::settings.get("engine_name"), sf::Style::None);

	// Events
	sf::Event event;

	/*-----------------
		PETLA CZASU
	-----------------*/
	sf::Clock timer;
	const float dt = .01f;
	float currentTime = timer.getElapsedTime().asSeconds();
	float accumulator = .0f;

	while (RootEngine::sceneManager.step())
	{
		// Obliczanie "akumulatora czasu"
		float newTime = timer.getElapsedTime().asSeconds();
		float frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		// Pobieranie aktywnej sceny
		Scene & active = RootEngine::sceneManager.getScene();

		// Sprawdzanie eventow
		while (window.pollEvent(event))
			active.inputs(event);

		// Liczenie fizyki, mechaniki silnika
		while (accumulator >= dt)
		{
			active.update(dt);
			accumulator -= dt;
		}

		// Rysowanie
		window.clear();
		active.draw(window);
		window.display();
	}

	return 0;
}