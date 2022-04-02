#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Food.h"
#include "Player.h"

class DeathScreen;

class Game
{
	std::vector<Food*> food;
	sf::RenderWindow* window;
	Player& player;
	bool game_running{ true };

	int score;
	int money = 200;
	std::string text{"Score: "};

	DeathScreen* deathScreen;
	
	//Sound (pickup)
	sf::SoundBuffer* pickup_buffer;
	sf::Sound* pickup_sound;

	// Money
	sf::Texture coin_texture;
	sf::Sprite coin;
	sf::Font coin_font;
	sf::Text coin_text;

public:
	Game(Player& p, sf::RenderWindow* w);
	void update();
	void spawn(Food* ad);
	void kill(Food* ad);
	void draw();
	void drawMoney();
	void catched();
	void fell();
	void gameOver();
	void drawDeathScreen();
	void runGame();
	bool gameRunning() { return game_running; };
	int& balance() { return money; };
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class DeathScreen
{
	// Window
	sf::RenderWindow* window;
	// Game Over
	sf::Font* gameOver_font;
	sf::Text* gameOver_text1;
	sf::Text* gameOver_text2;
	sf::Texture* gameOver_texture;
	sf::Sprite* gameOver_sprite;

	//Sound (game over)
	sf::SoundBuffer* death_buffer;
	sf::Sound* death_sound;
public:
	DeathScreen(sf::RenderWindow* w, std::string& text, int& score);
	~DeathScreen();
	void play();
};