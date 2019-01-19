#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Scene : public sf::Drawable
{
public:
	Scene();
	virtual ~Scene() {}

	virtual void handleEvent(const sf::RenderWindow& window) = 0;
	virtual void update() = 0;

	bool quit() const;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	bool m_quit;
};