#include "SFML\Graphics.hpp"
#include "SceneManager.h"
#include "Scene.h"

int main()
{
	// Main Window
	sf::RenderWindow window(sf::VideoMode(600, 700), "Tytul", sf::Style::None);

	// SceneManager
	SceneManager sceneManager;
	sceneManager.setScene(SceneInitializer::GAME_SCENE);

	// Events
	sf::Event event;

	/*-----------------
		PETLA CZASU
	-----------------*/
	sf::Clock timer;
	const float dt = .01f;
	float currentTime = timer.getElapsedTime().asSeconds();
	float accumulator = .0f;

	while (sceneManager.step())
	{
		// Obliczanie "akumulatora czasu"
		float newTime = timer.getElapsedTime().asSeconds();
		float frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		// Pobieranie aktywnej sceny
		Scene & active = sceneManager.getScene();

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