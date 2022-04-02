#include "Shop.h"
Shop::Shop(sf::RenderWindow* w, Player& p, sf::Sprite& b) : player{p}, bg_sprite{b}
{
	this->window = w;
	// Load to vector
	ShopItem* si = new ShopItem(100, "Assets/Textures/skin1.png", sf::Vector2f(199.9, 100.0));
	skins.push_back(*si);
	si = new ShopItem(100, "Assets/Textures/skin2.png", sf::Vector2f(373.3, 100.0));
	skins.push_back(*si);
	si = new ShopItem(100, "Assets/Textures/skin3.png", sf::Vector2f(546.6, 100.0));
	skins.push_back(*si);	
	si = new ShopItem(100, "Assets/Textures/skin4.png", sf::Vector2f(719.9, 100.0));
	skins.push_back(*si);
	si = new ShopItem(100, "Assets/Textures/skin5.png", sf::Vector2f(199.9, 300.0));
	skins.push_back(*si);
	si = new ShopItem(100, "Assets/Textures/skin6.png", sf::Vector2f(373.3, 300.0));
	skins.push_back(*si);
	si = new ShopItem(100, "Assets/Textures/skin7.png", sf::Vector2f(546.6, 300.0));
	skins.push_back(*si);
	si = new ShopItem(100, "Assets/Textures/skin8.png", sf::Vector2f(719.9, 300.0));
	skins.push_back(*si);
	// Background skins
	si = new ShopItem(100, "Assets/UI/Shop/bg_skin1_icon.png", sf::Vector2f(199.9, 600.0));
	bg_skins.push_back(*si);
	si = new ShopItem(100, "Assets/UI/Shop/bg_skin2_icon.png", sf::Vector2f(373.3, 600.0));
	bg_skins.push_back(*si);
	si = new ShopItem(100, "Assets/UI/Shop/bg_skin3_icon.png", sf::Vector2f(546.6, 600.0));
	bg_skins.push_back(*si);
	si = new ShopItem(100, "Assets/UI/Shop/bg_skin4_icon.png", sf::Vector2f(719.9, 600.0));
	bg_skins.push_back(*si);

	// Background
	bg_texture.loadFromFile("Assets/UI/Shop/shop_bg.png");
	bg.setTexture(bg_texture);
	for (int i = 0; i < bg_skins.size(); i++)
	{
		std::string path{ "Assets/Textures/bg_skin" };
		path += std::to_string(i + 1); path += ".png";
		bg_skins[i].setBackground(path);
	}

	// Font
	font.loadFromFile("Assets/Fonts/font.ttf");

	// Category text
	cat1.setFont(font);
	cat1.setString("Character skins");
	cat1.setCharacterSize(80);
	cat1.setOrigin(cat1.getGlobalBounds().width / 2, cat1.getGlobalBounds().height / 2);
	cat1.setPosition(500.0, 25.0);
	cat1.setOutlineColor(sf::Color::Black);
	cat1.setOutlineThickness(2);	
	
	// Category text2
	cat2.setFont(font);
	cat2.setString("Background skins");
	cat2.setCharacterSize(80);
	cat2.setOrigin(cat2.getGlobalBounds().width / 2, cat1.getGlobalBounds().height / 2);
	cat2.setPosition(500.0, 500.0);
	cat2.setOutlineColor(sf::Color::Black);
	cat2.setOutlineThickness(2);

	// Exit text
	x.setFont(font);
	x.setString("x");
	x.setCharacterSize(50);
	x.setPosition(0.0, -20.0);
	x.setFillColor(sf::Color::Black);

	// Info text
	info.setFont(font);
	info.setString("Click on item you bought to select");
	info.setCharacterSize(35);
	info.setOrigin(info.getGlobalBounds().width / 2, info.getGlobalBounds().height / 2);
	info.setPosition(500, 730);

	// Reset text
	reset.setFont(font);
	reset.setString("Reset skins to default");
	reset.setCharacterSize(40);
	reset.setOrigin(reset.getGlobalBounds().width / 2, reset.getGlobalBounds().height / 2);
	reset.setPosition(800, 770);
	reset.setFillColor(sf::Color::Black);
}
void Shop::draw()
{
	window->draw(bg); // Background
	for (int i = 0; i < skins.size(); i++) // Shop skins
		skins[i].draw(window);
	for (int i = 0; i < bg_skins.size(); i++) // Bg skins
		bg_skins[i].draw(window);

	window->draw(cat1); // Category text 1
	window->draw(cat2); // Category text 2
	window->draw(x); // Exit
	window->draw(info); // Info text
	window->draw(reset); // Reset text
}
void Shop::backIfClicked(int& ms)
{
	if (x.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			ms = 0;
	}
}
bool Shop::isClicking(sf::Sprite sprite)
{
	if (sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;

		return false;
	}
	return false;
}
void Shop::checkIfBought(int& money)
{
	if (reset.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		player.changeSkin("Assets/Textures/player.png");
		static sf::Texture default_texture;
		default_texture.loadFromFile("Assets/Textures/bg.png");
		bg_sprite.setTexture(default_texture);
	}
	for (int i = 0; i < skins.size(); i++)
	{
		if (isClicking(skins[i].getSprite()) == true)
		{
			skins[i].buy(money); // Buy

			if (skins[i].isBought() == true) // Set skin
			{
				ptr = i; // Current skin pointer points to the skin we currently wear
				player.changeSkin(skins[i].getPath());
			}
		}
	}
	for (int i = 0; i < bg_skins.size(); i++)
	{
		if (isClicking(bg_skins[i].getSprite()) == true)
		{
			bg_skins[i].buy(money); // Buy

			if (bg_skins[i].isBought() == true) // Set Bg skin
			{
				bgptr = i; // Current skin pointer points to the skin we currently wear
				bg_sprite.setTexture(*bg_skins[i].getBackground().getTexture());
			}
		}
	}
}
bool* Shop::isBought()
{
	int size = skins.size();
	bool* b_skins = new bool[size];
	for (int i = 0; i < size; i++)
	{
		b_skins[i] = skins[i].isBought();
	}

	return b_skins;
}
bool* Shop::isBgBought()
{
	int size = bg_skins.size();
	bool* b_skins = new bool[size];
	for (int i = 0; i < size; i++)
	{
		b_skins[i] = bg_skins[i].isBought();
	}

	return b_skins;
}
void Shop::loadSkins(bool* sk, int ptr)
{
	this->ptr = ptr;
	for (int i = 0; i < skins.size(); i++)
	{
		skins[i].loadData(sk[i]);
	}
	if (ptr != -1)
		player.changeSkin(skins[ptr].getPath()); // load current skin
	else 
		player.changeSkin("Assets/Textures/player.png"); // Else default skin
}
void Shop::loadBgSkins(bool* sk, int ptr)
{
	this->bgptr = ptr;
	for (int i = 0; i < bg_skins.size(); i++)
	{
		bg_skins[i].loadData(sk[i]);
	}
	if (bgptr != -1)
		bg_sprite.setTexture(*bg_skins[bgptr].getBackground().getTexture());
	else
	{
		static sf::Texture default_texture;
		default_texture.loadFromFile("Assets/Textures/bg.png");
		bg_sprite.setTexture(default_texture);
	}
}
int Shop::getPointer()
{
	return ptr;
}
int Shop::getBgPointer()
{
	return bgptr;
}