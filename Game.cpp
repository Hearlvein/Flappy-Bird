#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(800, 600), "Flappy Bird"),
	gameState(MenuState),
	m_currentScene(new Menu)
{
	m_window.setFramerateLimit(60);
	mainLoop();
}

Game::~Game()
{
	if (m_currentScene)
	{
		delete m_currentScene;
		m_currentScene = 0;
	}
}

void Game::mainLoop()
{
	while (m_window.isOpen())	// The window must be open
	{
		sf::Event event;	// Events managing routine

		while (m_window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				m_window.close();

		if (m_currentScene->quit())	// Change to the next scene
		{
			if (gameState == MenuState)
			{
				gameState = PlayState;

				delete m_currentScene;
				m_currentScene = new Play;
			}
			else
			{
				gameState = MenuState;

				delete m_currentScene;
				m_currentScene = new Menu;
			}
		}
		else // Do rendering routine
		{
			m_window.clear(sf::Color(20, 20, 20));

			m_currentScene->handleEvent(m_window);
			
			m_currentScene->update();
			m_window.draw(*m_currentScene);

			m_window.display();
		}
	}
}
