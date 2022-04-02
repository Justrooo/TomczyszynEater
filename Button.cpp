#include "Button.h"
Button::Button(sf::RenderWindow* w, std::string t, sf::Vector2f pos)
{
	window = w;
	// Text
	font.loadFromFile("Assets/UI/MainMenu/font.otf");
	text.setFont(font);
	text.setString(t);
	unsigned int size{};

	text.setCharacterSize(80);
	text.setPosition(pos);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);
}
void Button::draw()
{
	window->draw(text);
}
sf::Text Button::getText()
{
	return text;
}
void Button::setPosition(sf::Vector2f newPos)
{
	text.setPosition(newPos);
}