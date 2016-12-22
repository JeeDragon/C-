#ifndef BSPRITE_H
#define BSPRITE_H

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

class BSprite : public sf::Drawable, public sf::Transformable
{
public:
	BSprite(b2World* , int, float32, float32);
	~BSprite();
	void update(sf::Event &e, sf::RenderWindow &window);

private:
	b2World* world;
	b2Body* body;
	b2Fixture* fixture;
	sf::Sprite* sprite;
	sf::Texture* texture;
	const float SCALE = 30.0f;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates) const;
};

#endif // ! BSPRITE_H
