#include "PlayScene.h"

Play::Play() :
	m_backgroundImage(800.0f)
{
	if (!m_tileset.loadFromFile("res/tileset.png"))
		std::cout << "Unable to load the tileset" << std::endl;

	if (!m_backgroundTexture.loadFromFile("res/background.png"))
		std::cout << "Unable to load the background" << std::endl;

	if (!m_font.loadFromFile("res/font.ttf"))
		std::cout << "Unable to load the font" << std::endl;

	m_bird.setTexture(m_tileset);
	m_bird.setTextureRect(sf::IntRect(0, 0, 60, 50));
	m_bird.setOrigin(30, 25);
	m_bird.setPosition(200, 300);

	m_backgroundImage.setTexture(m_backgroundTexture);

	m_pipesMgr.setTexture(m_tileset);

	m_score.setFont(m_font);
	m_score.setPosition(5, 5);
	m_score.reset();
}

Play::~Play()
{
}

void Play::handleEvent(const sf::RenderWindow &window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
		m_bird.fly();
}

void Play::update()
{
	if (m_pipesMgr.birdColliding(m_bird.getGlobalBounds()))
		m_quit = true;

	m_bird.update();
	m_backgroundImage.update();
	m_pipesMgr.update(m_score);
}

void Play::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_backgroundImage);
	target.draw(m_bird);
	target.draw(m_pipesMgr);
	target.draw(m_score);
}