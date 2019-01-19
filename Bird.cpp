#include "Bird.h"

Bird::Bird() :
	m_flying(false)
{
}


Bird::~Bird()
{
}

void Bird::update()
{
	if (m_flying && m_lastFly.getElapsedTime().asMilliseconds() > 150)	// Le vol dure 150ms
	{
		m_flying = false;
	}

	if (m_flying)
	{
		move(0.0f, -8.0f);

		if (getPosition().y < 0.0f)	// Please don't go too much top ...
			setPosition(getPosition().x, 0.0f);
	}
	else
	{
		move(0.0f, 10.0f);	// Sorry, it's gravity ...

		if (getPosition().y > 600.0f)	// Please don't go too much bot ...
			setPosition(getPosition().x, 600.0f);
	}
}

void Bird::fly()
{
	if (!m_flying)
	{
		m_flying = true;
		m_lastFly.restart();
	}
}