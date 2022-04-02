#include "MainMenu.h"
MainMenu::MainMenu(sf::RenderWindow* w) : 
	play{PlayButton(w, "Play")},
	shop{ShopButton(w, "Shop")},
	exit{ExitButton(w, "Exit")}
{
	window = w;
	//play
	play.setPosition(sf::Vector2f(500 - play.getText().getGlobalBounds().width / 2, 350 - play.getText().getGlobalBounds().height / 2));
	//shop
	shop.setPosition(sf::Vector2f(500 - shop.getText().getGlobalBounds().width / 2, 450 - shop.getText().getGlobalBounds().height / 2));
	//exit
	exit.setPosition(sf::Vector2f(500 - exit.getText().getGlobalBounds().width / 2, 550 - exit.getText().getGlobalBounds().height / 2));
	
	// Load font
	font.loadFromFile("Assets/UI/MainMenu/game_title.ttf");
	// Title
	title.setFont(font);
	title.setString("Tomczyszyn Eater");
	title.setCharacterSize(82);
	title.setPosition(sf::Vector2f(500 - title.getGlobalBounds().width / 2, 70 - title.getGlobalBounds().height / 2));
	title.setOutlineColor(sf::Color::Black);
	title.setOutlineThickness(4);
	//Version
	version.setFont(font);
	version.setString("1.0 Beta");
	version.setCharacterSize(25);
	version.setPosition(885.0, 760.0);
	version.setOutlineColor(sf::Color::Black);
	version.setOutlineThickness(2);
	// Background
	background_texture.loadFromFile("Assets/UI/MainMenu/mainmenu_bg.png");
	background_sprite.setTexture(background_texture);
}
void MainMenu::draw()
{
	// Bg
	window->draw(background_sprite);
	// Title
	window->draw(title);
	// Version
	window->draw(version);
	// Buttons
	play.draw();
	shop.draw();
	exit.draw();
}
void MainMenu::update(int& menuState, Shop& s, Game& g, dataToSave& dataTS)
{
	if (isClicking(play.getText()) == true)
	{
		play.onClick(menuState);
	}
	else if (isClicking(shop.getText()) == true)
	{
		shop.onClick(menuState);
	}	
	else if (isClicking(exit.getText()) == true)
	{
		exit.onClick(s, g, dataTS);
	}
}
bool MainMenu::isClicking(sf::Text sprite)
{
	if (sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;

		return false;
	}
	return false;
}
/*
int MainMenu::getState()
{
	return menuState;
}
void MainMenu::setState(int st)
{
	menuState = st;
}*/