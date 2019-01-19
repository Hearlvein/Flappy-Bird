#include "Button.h"

Button::Button()
{
	m_rect.setFillColor(sf::Color::Magenta);
}

Button::~Button()
{
}

void Button::setFont(sf::Font &font)
{
	m_text.setFont(font);
}

void Button::setString(sf::String text)
{
	m_text.setString(text);
}

void Button::setPosition(float x, float y)
{
	sf::FloatRect textRect = m_text.getLocalBounds();
	float padding = 20.0f;

	m_text.setPosition(x + padding, y + padding);
	m_rect.setSize(sf::Vector2f(textRect.width + 2 * padding, textRect.height + 2 * padding));
	m_rect.setPosition(sf::Vector2f(x, y));
}

sf::FloatRect Button::getBoundingBox()
{
	sf::FloatRect bb =  m_rect.getLocalBounds();
	sf::Vector2f pos = m_rect.getPosition();

	bb.left += pos.x;
	bb.top += pos.y;

	return bb;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rect, states);
	target.draw(m_text, states);
}
