#include "Food.h"
#include <iostream>
Food::Food(std::string path)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}
void Food::update()
{
	if (visible == true)
		sprite.move(0, velocity);
}
void Food::reset()
{
	visible = false;
	dead = true;
}
void Food::spawn()
{
	sprite.setPosition(rand() % 961, 0);
	dead = false;
	visible = true;
}
bool Food::isVisible()
{
	return visible;
}
Food::~Food()
{
	delete pickup_buffer;
	delete pickup_sound;
}