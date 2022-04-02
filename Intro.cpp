#include "Intro.h"
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

Intro::Intro(sf::RenderWindow& w) : window{w}
{
	// Sound
	buffer = new sf::SoundBuffer;
	sound = new sf::Sound;
	buffer->loadFromFile("Intro/Intro_sound.wav");
	sound->setBuffer(*buffer);
	sound->setVolume(40);
	// Font
	font = new sf::Font;
	font->loadFromFile("Intro/Intro_font.ttf");
	// Text 1
	text1 = new sf::Text;
	text1->setFont(*font);
	text1->setString("Justro");
	text1->setCharacterSize(169);
	text1->setStyle(sf::Text::Bold);
	text1->setOrigin(text1->getLocalBounds().width / 2, text1->getLocalBounds().height);
	text1->setPosition(window.getSize().x / 2, window.getSize().y / 2);
	// Text 2
	text2 = new sf::Text;
	text2->setFont(*font);
	text2->setString("made by:");
	text2->setCharacterSize(30);
	text2->setOrigin(text2->getLocalBounds().width / 2, text2->getLocalBounds().height);
	text2->setPosition(window.getSize().x / 2, window.getSize().y / 2 - 100);
}
void Intro::play()
{
	static bool played = false;
	if (played == false)
	{
		sound->play();
	}
	static int i{};
	if (started == false)
	{
		if (i <= 255)
		{
			text1->setFillColor(sf::Color(255, 255, 255, i));
			text2->setFillColor(sf::Color(255, 255, 255, i));
			window.clear(sf::Color::Black);
			window.draw(*text1);
			window.draw(*text2);

			sleep_for(milliseconds(11));
			i++;
			played = true;
		}
	}
	if (i == 255) // End of intro, unload everything
	{
		started = true;
	}
}
Intro::~Intro()
{
	delete buffer;
	delete sound;
	delete font;
	delete text1;
	delete text2;
}