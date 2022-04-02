#include "ShopItem.h"
ShopItem::ShopItem(int price, std::string p, sf::Vector2f pos)
{
	this->price = price;
	this->path = p;

	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(pos);

	// Price tag
	font.loadFromFile("Assets/Fonts/font.ttf");
	price_tag.setFont(font);
	price_tag.setString(std::to_string(price));
	price_tag.setCharacterSize(40);
	price_tag.setOrigin(price_tag.getGlobalBounds().width / 2, price_tag.getGlobalBounds().height / 2);
	price_tag.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height + 10);
	price_tag.setFillColor(sf::Color::Yellow);
}
void ShopItem::draw(sf::RenderWindow* w)
{
	w->draw(price_tag);
	w->draw(sprite);
}
void ShopItem::buy(int& total_cash)
{
	if (total_cash >= price && sold == false)
	{
		total_cash -= price;
		sold = true;

		price_tag.setString("SOLD");
		price_tag.setFillColor(sf::Color::Red);
		price_tag.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height + 10);
	}
}
void ShopItem::setBackground(std::string path)
{
	bg_texture.loadFromFile(path);
	bg_sprite.setTexture(bg_texture);
}
void ShopItem::loadData(bool isSold)
{
	sold = isSold;
	if (sold == true)
	{
		price_tag.setString("SOLD");
		price_tag.setFillColor(sf::Color::Red);
		price_tag.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height + 10);
	}
}