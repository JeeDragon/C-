#ifndef BSPRITE_H
#define BSPRITE_H

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

class Pikachu : public sf::Drawable, public sf::Transformable
{
public:
	Pikachu();
	~Pikachu();
	void update(sf::Event &e, sf::RenderWindow &window);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates) const;
	sf::Sprite *sprite;
	sf::Texture *texture;
};

#endif
