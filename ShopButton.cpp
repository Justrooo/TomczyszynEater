#include "ShopButton.h"
ShopButton::ShopButton(sf::RenderWindow* w, std::string t, sf::Vector2f pos) : Button(w, t, pos)
{
}
void ShopButton::onClick(int& menuState)
{
	menuState = 2;
}
/*
menuState of 0: main menu,
menuState of 1: game,
menuState of 2: shop,
*/