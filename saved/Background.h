#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Background : public sf::Sprite
{
public:
	Background(float highestInterval);
	virtual ~Background();

	void update();

private:
	float m_highestInterval;
	float m_interval;
	sf::Clock m_lastTranslation;
};

