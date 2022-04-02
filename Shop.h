#pragma once
#include "ShopItem.h"
#include "Player.h"
#include <vector>
class Shop
{
	sf::RenderWindow* window;

	std::vector<ShopItem> skins;
	std::vector<ShopItem> bg_skins;
	// Background
	sf::Texture bg_texture;
	sf::Sprite bg;
	// Font
	sf::Font font;
	// Category text 1 (character skins)
	sf::Text cat1;
	// Category text 2 (background skins)
	sf::Text cat2;
	// Exit text
	sf::Text x;
	// Info text
	sf::Text info;
	// Reset default skin button
	sf::Text reset;

	// Pointer to skins that we wear
	int ptr;
	int bgptr;

	//Player&, Sprite&
	Player& player;
	sf::Sprite& bg_sprite;

	bool isClicking(sf::Sprite sprite);
public:
	Shop(sf::RenderWindow* w, Player& player, sf::Sprite& b);
	void draw();
	void backIfClicked(int& ms);
	void checkIfBought(int& money);
	bool* isBought();
	bool* isBgBought();
	void loadSkins(bool* sk, int ptr);
	void loadBgSkins(bool* sk, int ptr);
	int getPointer();
	int getBgPointer();
};