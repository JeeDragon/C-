#include "BSprite.h"

using namespace sf;

/// <Summary>
/// Constructs a new BSprite object.
/// </Summary>
BSprite::BSprite(b2World* world, int pokemon, b2BodyType bType, float32 x, float32 y)
{
	this->world = world;
	contact = false;
	
	// Body definition
	b2BodyDef def;


	if (bType == b2_dynamicBody)
		def.type = b2_dynamicBody;
	else if (bType == b2_staticBody)
		def.type = b2_staticBody;
	else
		def.type = b2_kinematicBody;

	def.angle = 0;
	def.position.Set(x / SCALE, y / SCALE);
	body = world->CreateBody(&def);
	body->SetUserData(this);

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
	fixtureDef.restitution = 0.0f;

	texture = new Texture();

	//texture->loadFromFile("../resources/pikachu.png");
	// TODO: add image offset
	if (pokemon == 0)
	{
		circle.m_radius = 2.2f;
		fixtureDef.shape = &circle;
		texture->loadFromFile("../resources/sphere0.png");
		fixture = body->CreateFixture(&fixtureDef);
		sprite = new Sprite();
		sprite->setTexture((*texture));
		sprite->setPosition(x - 60.0f, y - 100.0f);
		//sprite->setOrigin(Vector2f(-40.0f, -50.0f));
	}
	else if (pokemon == 1)
	{
		fixtureDef.shape = &boxShape;
		texture->loadFromFile("../resources/pikachu.png");
		fixture = body->CreateFixture(&fixtureDef);
		sprite = new Sprite();
		sprite->setTexture((*texture));
		sprite->setPosition(x, y);
	}
	else if (pokemon == 2)
	{
		boxShape.SetAsBox(3, 3);
		fixtureDef.shape = &boxShape;
		texture->loadFromFile("../resources/warturtle.png");
		fixture = body->CreateFixture(&fixtureDef);
		sprite = new Sprite();
		sprite->setTexture((*texture));
		sprite->scale(Vector2f(0.5f, 0.5f));
		sprite->setPosition(x, y);
	}
	else if (pokemon == 3)
	{
		circle.m_radius = 0.2f;
		fixtureDef.shape = &circle;
		fixtureDef.friction = 1;
		fixtureDef.restitution = 0.5;
		texture->loadFromFile("../resources/pokeball.png");
		fixture = body->CreateFixture(&fixtureDef);
		sprite = new Sprite();
		sprite->setTexture((*texture));
		sprite->setOrigin(Vector2f(-4.0f, 0.0f));
		sprite->setPosition(x, y);
		sprite->scale(Vector2f(0.075f, 0.075f));
	}	
	else if (pokemon == 4)
	{
		
		fixtureDef.shape = &boxShape;
		texture->loadFromFile("../resources/charmander.png");
		fixture = body->CreateFixture(&fixtureDef);
		sprite = new Sprite();
		sprite->setTexture((*texture));
		sprite->setPosition(x - 200, y - 200);
		
	}
	else if (pokemon == 5)
	{
		boxShape.SetAsBox(1.85, 1.85);
		fixtureDef.shape = &boxShape;
		texture->loadFromFile("../resources/microsoft.png", IntRect(10, 10, 300, 290));
		fixture = body->CreateFixture(&fixtureDef);
		fixture->SetFriction(4);
		sprite = new Sprite();
		sprite->setTexture((*texture));

		float xx = (x / SCALE) + 23;
		float yy = (y / SCALE) + 44;
		sprite->setOrigin(xx, yy);
		//sprite->setPosition(xx, yy);
		//sprite->setPosition(x - 200, y - 200);
	}
	else if (pokemon == 6)
	{
		boxShape.SetAsBox(2, 3);
		fixtureDef.shape = &boxShape;
		texture->loadFromFile("../resources/battery.png");
		fixture = body->CreateFixture(&fixtureDef);
		sprite = new Sprite();
		sprite->setTexture((*texture));
		sprite->scale(Vector2f(1.3f, 1.3f));

		float xx = (x / SCALE) + 35;
		float yy = (y / SCALE) + 60;
		sprite->setOrigin(xx, yy);
	}
	
	//fixture = body->CreateFixture(&fixtureDef);
	//sprite = new Sprite();
	//sprite->setTexture((*texture));
	//sprite->setPosition(x, y);
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

	int mouseX = Mouse::getPosition(window).x;
	int mouseY = Mouse::getPosition(window).y;

	if (Mouse::isButtonPressed(Mouse::Left) && fixture->TestPoint(b2Vec2(mouseX / SCALE, mouseY / SCALE)))
	{
		texture->loadFromFile("../resources/blastoise.png");
		sprite->setTexture((*texture));
	}

	body->SetAngularVelocity(0);
	
	sprite->setPosition(position.x * SCALE, position.y * SCALE);

	sprite->setRotation((angle * 180) / b2_pi);
}

bool BSprite::equal(b2Body * other)
{
	if (body == other)
	{
		return true;
	}
	return false;
}

void BSprite::playSound(int)
{
}

void BSprite::startContact()
{
	contact = true;
}

void BSprite::endContact()
{
	contact = false;
}

/// <Summary>
/// Draws the sprite.
/// </Summary>
void BSprite::draw(RenderTarget &target, RenderStates) const
{
	target.draw((*sprite));
}
