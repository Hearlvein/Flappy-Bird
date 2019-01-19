#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Bird : public sf::Sprite
{
public:
	Bird();
	~Bird();

	void update();
	void fly();

private:
	bool m_flying;
	sf::Clock m_lastFly;
};