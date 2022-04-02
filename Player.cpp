#include "Player.h"

Player::Player(std::string path)
{
	this->path = path;

	texture.loadFromFile(path);
	sprite.setTexture(texture);

	sprite.setPosition(500.f, 700.f);
}
void Player::update()
{
	// Movement //
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		//sprite.move(0.f, -velocity);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		//sprite.move(0.f, velocity);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.move(-velocity, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.move(velocity, 0.f);
	// Movement //
	float szerokosc = sprite.getGlobalBounds().width;
	float wysokosc = sprite.getGlobalBounds().height;
	// Collision with screen //
		// Left
	if (sprite.getPosition().x < 0.f)
		sprite.setPosition(0.f, sprite.getPosition().y);
	// Top
	if (sprite.getPosition().y < 0.f)
		sprite.setPosition(sprite.getPosition().x, 0.f);
	// Right
	if (sprite.getPosition().x + szerokosc > 1000)
		sprite.setPosition(1000 - szerokosc, sprite.getPosition().y);
	// Bottom
	if (sprite.getPosition().y + wysokosc > 800)
		sprite.setPosition(sprite.getPosition().x, 800 - wysokosc);
	// Collision with screen //
}
sf::Sprite Player::getSprite()
{
	return sprite;
}
bool Player::collides(Food obj)
{
	if (sprite.getGlobalBounds().intersects(obj.getSprite().getGlobalBounds()))
		return true;
	else
		return false;
}
void Player::changeSkin(std::string path)
{
	this->path = path;
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}