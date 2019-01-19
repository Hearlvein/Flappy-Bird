#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public sf::Drawable
{
public:
	Button();
	virtual ~Button();
	
	void setFont(sf::Font &font);
	void setString(sf::String text);
	void setPosition(float x, float y);
	sf::FloatRect getBoundingBox();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::RectangleShape m_rect;
	sf::Text m_text;
};