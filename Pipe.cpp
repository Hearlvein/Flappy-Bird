#include "Pipe.h"

Pipe::Pipe(bool onGround, int size, sf::Texture& texture)
{
	m_body.setTextureRect(sf::IntRect(60, 0, 50, size - 15));
	m_entry.setTextureRect(sf::IntRect(0, 50, 60, 15));

	m_body.setTexture(texture);
	m_entry.setTexture(texture);

	if (onGround)
	{
		m_entry.setPosition(800, (float)(600 - size));
		m_body.setPosition(805, (float)(615 - size));
	}
	else
	{
		m_entry.setPosition(800, (float)(size - 15));
		m_body.setPosition(805, 0.0f);
	}
}

Pipe::~Pipe()
{
}

void Pipe::translate(float xOffset)
{
	// The offset is necessary positive but call to sf::Transformable::move() is negative
	m_entry.move(-xOffset, 0);
	m_body.move(-xOffset, 0);
}

const sf::FloatRect Pipe::getEntryBounds() const
{
	return m_entry.getGlobalBounds();
}

const sf::FloatRect Pipe::getBodyBounds() const
{
	return m_body.getGlobalBounds();
}

void Pipe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_entry);
	target.draw(m_body);
}
