#include "Pikachu.h"

Pikachu::Pikachu()
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	if (texture->loadFromFile("../resources/pokemon/pikachu.png")) { }
	sprite->setTexture(*texture);
	sprite->setPosition(sf::Vector2f(100, 100));
}

Pikachu::~Pikachu()
{
	delete sprite;
	delete texture;
}

void Pikachu::update(sf::Event & e, sf::RenderWindow & window)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->move(sf::Vector2f(-2.0f, 0.0f));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->move(sf::Vector2f(2.0f, 0.0f));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		sprite->move(sf::Vector2f(0.0f, -2.0f));
		//this->move(sf::Vector2f(0.0f, 2.0f));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->move(sf::Vector2f(0.0f, -2.0f));

}

void Pikachu::draw(sf::RenderTarget &target, sf::RenderStates) const
{
	target.draw((*sprite));
}
