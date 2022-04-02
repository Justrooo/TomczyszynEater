#pragma once
#include "Button.h"
class PlayButton :
    public Button
{
public:
    PlayButton(sf::RenderWindow* w, std::string t, sf::Vector2f pos = sf::Vector2f());
    void onClick(int& menuState);
};