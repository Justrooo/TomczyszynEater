#pragma once
#include <SFML/Graphics.hpp>
class Button
{
protected:
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text text;
public:
	Button(sf::RenderWindow* w = nullptr, std::string t = "OK", sf::Vector2f pos = sf::Vector2f(0.0, 0.0));
	void draw();
	void setPosition(sf::Vector2f newPos);
	sf::Text getText();
};