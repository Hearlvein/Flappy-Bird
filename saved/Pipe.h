#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Pipe : public sf::Drawable
{
public:
	Pipe(bool onGround, int size, sf::Texture& texture);
	~Pipe();

	void translate(float xOffset);

	// Two methods to perform a collision check
	const sf::FloatRect getEntryBounds() const;
	const sf::FloatRect getBodyBounds() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::Sprite m_entry;
	sf::Sprite m_body;
};