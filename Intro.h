#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>

class Intro
{
	// Window 
	sf::RenderWindow& window;
	// Sound
	sf::SoundBuffer* buffer;
	sf::Sound* sound;
	// Text
	sf::Font* font;
	sf::Text* text1;
	sf::Text* text2;
	bool started = false;
public:
	Intro(sf::RenderWindow& w);
	~Intro();
	void play();
	bool intro_started() { return started; };
};