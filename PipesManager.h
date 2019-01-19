#pragma once
#include <SFML\Graphics.hpp>
#include "Pipe.h"
#include "Score.h"
#include <deque>

class PipesManager : public sf::Drawable
{
public:
	PipesManager();
	~PipesManager();

	void update(Score& score);

	void setTexture(sf::Texture& texture);
	bool birdColliding(const sf::FloatRect& birdRect);

private:
	void addPipe();
	void translate(float xOffset = 8);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	std::deque <Pipe> m_pipesList;
	sf::Texture* m_tileset;
	sf::Clock m_lastAdd;
};