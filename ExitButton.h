#pragma once
#include "Button.h"
#include "data.h"
#include "Game.h"
#include "Shop.h"
class ExitButton :
    public Button
{
public:
    ExitButton(sf::RenderWindow* w, std::string t, sf::Vector2f pos = sf::Vector2f());
    void onClick(Shop& shop, Game& game, dataToSave& dataTS);
};