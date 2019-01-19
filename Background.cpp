#include "Background.h"

Background::Background(float highestInterval) :
	m_highestInterval(highestInterval),
	m_interval(0)
{
}

void Background::update()
{
	if (m_interval >= m_highestInterval)	// Reset background
	{
		setPosition(0, 0);
		m_interval = 0.0f;
		m_lastTranslation.restart();
	}

	if (m_lastTranslation.getElapsedTime().asMilliseconds() > 20)
	{
		m_interval += 4.0f;
		move(-4, 0);
	}
}

Background::~Background()
{
}