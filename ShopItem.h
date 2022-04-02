#pragma once
#include <SFML/Graphics.hpp>
class ShopItem
{
	int price;
	bool sold = false;
	// Preview
	sf::Texture texture;
	sf::Sprite sprite;	
	std::string path;
	// For background skins 
	sf::Texture bg_texture;
	sf::Sprite bg_sprite;
	//std::string bg_path;
	// Price tag
	sf::Font font;
	sf::Text price_tag;
public:
	ShopItem(int price = 10, std::string p = nullptr, sf::Vector2f pos = sf::Vector2f());
	void draw(sf::RenderWindow* w);
	void buy(int& total_cash);
	void setBackground(std::string path);
	void loadData(bool isSold);
	int getPrice() { return price; };
	bool isBought() { return sold; };
	sf::Sprite& getBackground() { return bg_sprite; };
	std::string getPath() { return path; };
	sf::Sprite& getSprite() { return sprite; };
};