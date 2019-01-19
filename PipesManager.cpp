#include "PipesManager.h"

PipesManager::PipesManager()
{
	srand((unsigned int)time(0));
}

PipesManager::~PipesManager()
{
}

void PipesManager::update(Score& score)
{
	translate();

	if (m_lastAdd.getElapsedTime().asSeconds() > 1)
	{
		addPipe();
		score.increment();
		m_lastAdd.restart();
	}
}

void PipesManager::setTexture(sf::Texture& texture)
{
	m_tileset = &texture;
}

void PipesManager::translate(float xOffset)
{
	for (unsigned int i = 0; i < m_pipesList.size(); ++i)
	{
		m_pipesList[i].translate(xOffset);
	}
}

bool PipesManager::birdColliding(const sf::FloatRect& birdRect)
{
	for (unsigned int i = 0; i < m_pipesList.size(); ++i)
		if (birdRect.intersects(m_pipesList[i].getEntryBounds()) || birdRect.intersects(m_pipesList[i].getBodyBounds()))
			return true;

	return false;
}

void PipesManager::addPipe()
{
	if (m_pipesList.size() > 2)	// Less than 3 in memory
		m_pipesList.pop_front();

	bool onGround = true;	// Decide if the pipe is on the ground
	if (rand() % 2 == 0)
		onGround = false;

	Pipe pipeToAdd(onGround, rand() % 300 + 100, *m_tileset);

	m_pipesList.push_back(pipeToAdd);
}

void PipesManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_pipesList.size(); ++i)
	{
		target.draw(m_pipesList[i]);
	}
}
