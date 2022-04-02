#pragma once
#include "Button.h"
class ShopButton :
    public Button
{
public:
    ShopButton(sf::RenderWindow* w, std::string t, sf::Vector2f pos = sf::Vector2f());
    void onClick(int& menuState);
};
