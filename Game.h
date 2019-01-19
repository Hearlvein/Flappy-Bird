#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Scene.h"
#include "MenuScene.h"
#include "PlayScene.h"

enum GameStates {
	MenuState,
	PlayState
};

class Game
{
public:
	Game();
	~Game();

	void mainLoop();

private:
	sf::RenderWindow m_window;
	GameStates gameState;
	Scene *m_currentScene;
};