#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Food
{
	sf::Texture texture;
	sf::Sprite sprite;
	float velocity = 5.f;
	bool dead = false;
	bool visible = true;

	//Sound (pickup)
	sf::SoundBuffer* pickup_buffer;
	sf::Sound* pickup_sound;
public:
	explicit Food(std::string path);
	~Food();
	sf::Sprite getSprite() { return sprite; };
	//void setVisible(bool v) { visible = v; };
	void update();
	void spawn();
	void reset();
	bool isVisible();
};