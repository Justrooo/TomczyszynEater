#pragma once
#include "PlayButton.h"
#include "ShopButton.h"
#include "Game.h"
#include "ExitButton.h"

class MainMenu
{
	//Window
	sf::RenderWindow* window;
	//Buttons
	PlayButton play;
	ShopButton shop;
	ExitButton exit;
	//Background
	sf::Texture background_texture;
	sf::Sprite background_sprite;
	//Font
	sf::Font font;
	//Game Title
	sf::Text title;
	//Version text
	sf::Text version;

	//TODO: Music etc.
	//int menuState = 0;
	bool isClicking(sf::Text sprite);
public:
	MainMenu(sf::RenderWindow* w);
	void draw();
	void update(int& menuState, Shop& s, Game& g, dataToSave& dataTS);
	
	//void setState(int st);
	//int getState();
};