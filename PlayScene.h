#pragma once

#include "Scene.h"
#include "Bird.h"
#include "Background.h"
#include "PipesManager.h"
#include "Score.h"
#include <SFML\Graphics.hpp>

class Play : public Scene
{
public:
	Play();
	virtual ~Play();

	virtual void handleEvent(const sf::RenderWindow& window) override;
	virtual void update() override;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Resources
	sf::Texture m_tileset;
	sf::Texture m_backgroundTexture;
	sf::Font m_font;

	// Game objects
	Bird m_bird;
	Background m_backgroundImage;
	PipesManager m_pipesMgr;
	Score m_score;
};