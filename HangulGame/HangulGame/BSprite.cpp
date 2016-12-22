#include "BSprite.h"

using namespace sf;

/// <Summary>
/// Constructs a new BSprite object.
/// </Summary>
BSprite::BSprite(b2World* world, int pokemon, float32 x, float32 y)
{
	this->world = world;


	// Body definition
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.angle = 0;
	def.position.Set(x / SCALE, y / SCALE);
	body = world->CreateBody(&def);

	// Box
	b2PolygonShape boxShape;
	boxShape.SetAsBox(1, 2);

	// Circle
	b2CircleShape circle;
	circle.m_p.Set(0, 0);
	circle.m_radius = 1.8f;

	// Fixture definition
	b2FixtureDef fixtureDef;
	fixtureDef.density = 1;
	fixtureDef.restitution = 1;
	//fixtureDef.shape = &circle;

	texture = new Texture();

	//texture->loadFromFile("../resources/pikachu.png");
	// TODO: add image offset
	if (pokemon == 0)
	{
		fixtureDef.shape = &circle;
		texture->loadFromFile("../resources/sphere0.png");
	}
	else if (pokemon == 1)
	{
		fixtureDef.shape = &boxShape;
		texture->loadFromFile("../resources/pikachu.png");
	}
	else if (pokemon == 2)
	{
		fixtureDef.shape = &boxShape;
		texture->loadFromFile("../resources/squirtle.png");
	}
	else if (pokemon == 3)
	{
		fixtureDef.shape = &circle;
		texture->loadFromFile("../resources/pokeball.png");
	}	
	else if (pokemon == 4)
	{
		fixtureDef.shape = &boxShape;
		texture->loadFromFile("../resources/charmander.png");
	}
	
	fixture = body->CreateFixture(&fixtureDef);
	sprite = new Sprite();
	sprite->setTexture((*texture));
	sprite->setPosition(x, y);
}

/// <Summary>
/// Cleans up any resources the BSprite uses.
/// </Summary>
BSprite::~BSprite()
{
	body->DestroyFixture(fixture);
	world->DestroyBody(body);
	delete sprite;
	delete texture;
}

/// <Summary>
/// Updates the sprites position
/// </Summary>
void BSprite::update(Event &e, RenderWindow &window)
{
	b2Vec2 position = body->GetPosition();
	float32 angle = body->GetAngle();

	sprite->setPosition(position.x * SCALE, position.y * SCALE);

	sprite->setRotation((angle * 180) / b2_pi);
}

/// <Summary>
/// Draws the sprite.
/// </Summary>
void BSprite::draw(RenderTarget &target, RenderStates) const
{
	target.draw((*sprite));
}
