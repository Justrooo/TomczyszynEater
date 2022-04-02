#include "Game.h"
#include <iostream>
Game::Game(Player& p, sf::RenderWindow* w) : player{ p }
{
	window = w;
	pickup_buffer = new sf::SoundBuffer;
	pickup_sound = new sf::Sound;
	pickup_buffer->loadFromFile("Assets/Sounds/pickup.wav");
	pickup_sound->setBuffer(*pickup_buffer);

	coin_texture.loadFromFile("Assets/Textures/coin.png");
	coin.setTexture(coin_texture);
	coin.setPosition(958.0, 5.0);

	coin_font.loadFromFile("Assets/Fonts/font.ttf");
	coin_text.setFont(coin_font);
	coin_text.setCharacterSize(40);
	coin_text.setPosition(928.0, 0.0);
}
void Game::update()
{
	if (game_running)
		for (auto& f : food) f->update();
}
void Game::spawn(Food* ad)
{
	ad->spawn();
	food.push_back(ad);
}
void Game::kill(Food* ad)
{
	if (food.empty() == false)
	{
		if (game_running)
		{
			for (unsigned int i = 0; i < food.size(); i++)
			{
				if (food[i] == ad)
				{
					delete food[i];
					food.erase(food.begin() + i);
					break;
				}
			}
		}
	}
}
void Game::draw()
{
	if (game_running)
	{
		for (auto& f : food)
		{
			if (f->isVisible() == true)
				window->draw(f->getSprite());
		}
	}
}
void Game::drawMoney()
{
	coin_text.setString(std::to_string(money));
	if (coin_text.getPosition().x + coin_text.getGlobalBounds().width > coin.getPosition().x)
		coin_text.move(-10.0, 0.0);
	window->draw(coin);
	window->draw(coin_text);
}
void Game::catched()
{
	bool collected{false};
	if (game_running && food.empty() == false)
	{
		int i{};
		for (auto& f : food)
		{
			if (player.collides(*f))
			{
				pickup_sound->play();
				f->reset();
				delete food[i];
				food.erase(food.begin() + i);
				collected = true;
				score++;		
				money+=100;
			}
			i++;
		}
	}
	if (collected == true)
	{

	}
}
void Game::fell()
{
	if (game_running)
	{
		int i{};
		for (auto& f : food)
		{
			if (f->getSprite().getPosition().y + f->getSprite().getGlobalBounds().height >= 800)
			{
				f->reset();
				delete food[i];
				food.erase(food.begin() + i);
				gameOver();
			}
			i++;
		}
	}
}
void Game::gameOver()
{
	delete pickup_buffer;
	delete pickup_sound;

	deathScreen = new DeathScreen(window, text, score);

	food.clear();
	game_running = false;
}
void Game::drawDeathScreen()
{
	deathScreen->play();
}
void Game::runGame()
{
	delete deathScreen;
	pickup_buffer = new sf::SoundBuffer;
	pickup_sound = new sf::Sound;
	pickup_buffer->loadFromFile("Assets/Sounds/pickup.wav");
	pickup_sound->setBuffer(*pickup_buffer);

	// run game so unload (delete) death screen so we can save some memory

	score = 0;
	game_running = true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
DeathScreen::DeathScreen(sf::RenderWindow* w, std::string& text, int& score)
{
	// Prepare death screen

// Allocation

// GameOver screen
	gameOver_font = new sf::Font;
	gameOver_text1 = new sf::Text;
	gameOver_text2 = new sf::Text;
	gameOver_texture = new sf::Texture;
	gameOver_sprite = new sf::Sprite;
	// GameOver sound
	death_buffer = new sf::SoundBuffer;
	death_sound = new sf::Sound;
	death_buffer->loadFromFile("Assets/Sounds/death.wav");
	death_sound->setBuffer(*death_buffer);
	death_sound->play();
	//Font
	gameOver_font->loadFromFile("Assets/Fonts/font.ttf");
	//Text 1
	gameOver_text1->setFont(*gameOver_font);
	gameOver_text1->setString("RIP. Press space to restart or\n escape to return to menu");
	gameOver_text1->setCharacterSize(50);
	gameOver_text1->setOrigin(gameOver_text1->getLocalBounds().width / 2., gameOver_text1->getLocalBounds().height / 2.);
	gameOver_text1->setPosition(500, 150);
	//Text2
	gameOver_text2->setFont(*gameOver_font);
	gameOver_text2->setString(text + std::to_string(score));
	gameOver_text2->setCharacterSize(80);
	gameOver_text2->setOrigin(gameOver_text2->getLocalBounds().width / 2., gameOver_text2->getLocalBounds().height / 2.);
	gameOver_text2->setPosition(500, 600);
	//Image
	gameOver_texture->loadFromFile("Assets/Textures/dead.png");
	gameOver_sprite->setTexture(*gameOver_texture);
	gameOver_sprite->setOrigin(gameOver_sprite->getLocalBounds().width / 2., gameOver_sprite->getLocalBounds().height / 2.);
	gameOver_sprite->setPosition(500, 400);

	// Allocation
	window = w;
}
void DeathScreen::play()
{
	// Draw Death Screen
	window->draw(*gameOver_text1);
	window->draw(*gameOver_sprite);
	window->draw(*gameOver_text2);
}
DeathScreen::~DeathScreen()
{
	delete gameOver_font;
	delete gameOver_text1;
	delete gameOver_text2;
	delete gameOver_texture;
	delete gameOver_sprite;
	delete death_buffer;
	delete death_sound;
}