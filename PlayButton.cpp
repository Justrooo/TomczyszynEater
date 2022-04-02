#include "PlayButton.h"
PlayButton::PlayButton(sf::RenderWindow* w, std::string t, sf::Vector2f pos) : Button(w, t, pos)
{
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
void PlayButton::onClick(int& menuState)
{
	menuState = 1;
}
/*
menuState of 0: main menu,
menuState of 1: game,
menuState of 2: shop,	
*/