#pragma once

#include "Scene.h"
#include "Button.h"

class Menu : public Scene
{
public:
	Menu();
	virtual ~Menu();

	virtual void handleEvent(const sf::RenderWindow& window) override;
	virtual void update() override;

	void onClick(const sf::RenderWindow& window);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundImage;
	sf::Font m_font;
	Button m_button;
};