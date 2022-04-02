#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Food.h"
#include "ShopItem.h"

class Player
{
	sf::Texture texture;
	sf::Sprite sprite;
	std::string path;

	bool has_skin = false;
	float velocity = 5.f;
public:
	explicit Player(std::string path);
	void update();
	sf::Sprite getSprite();
	bool collides(Food obj);
	void changeSkin(std::string path);
};
