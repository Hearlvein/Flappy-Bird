#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Score : public sf::Text
{
public:
	Score();
	~Score();

	void reset();
	void increment();

private:
	unsigned int m_score;
};

