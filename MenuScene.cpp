#include "MenuScene.h"

Menu::Menu()
{
	if (!m_backgroundTexture.loadFromFile("res/background.png"))
		std::cout << "Unable to load the background texture" << std::endl;

	m_backgroundImage.setTexture(m_backgroundTexture);

	if (!m_font.loadFromFile("res/font.ttf"))
		std::cout << "Unable to load the font" << std::endl;

	m_button.setFont(m_font);
	m_button.setString(sf::String("Jouer"));
	m_button.setPosition(300.0f, 400.0f);
}

Menu::~Menu()
{

}
 
void Menu::handleEvent(const sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		onClick(window);
}

void Menu::update()
{
	;	// Menu not automatically interactive
}

void Menu::onClick(const sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::FloatRect buttonBoundingBox = m_button.getBoundingBox();

	if (mousePos.x > buttonBoundingBox.left &&
		mousePos.x < buttonBoundingBox.left + buttonBoundingBox.width &&
		mousePos.y > buttonBoundingBox.top &&
		mousePos.y < buttonBoundingBox.top + buttonBoundingBox.height)
	{
		m_quit = true;
	}
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_backgroundImage);
	target.draw(m_button);
}
