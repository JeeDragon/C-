#include "Box2dSimulation.h"
#include <Box2D\Box2D.h>
#include "BSprite.h"

/// <Summary>
/// Constructs a new Box 2d Simulation.
/// </Summary>
Box2dSimulation::Box2dSimulation()
{
	b2Vec2 gravity(0.0f, 9.8f);
	world = new b2World(gravity);

	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(0 / 30.f, 0 / 30.f);
	ground = world->CreateBody(&myBodyDef);

	float w = 1280.0f;
	float h = 720.0f;

	w = w - 10;
	h = h - 15;

	b2EdgeShape shape;
	shape.Set(b2Vec2(0.0f, 0.0f), b2Vec2(w / SCALE, 0.0f));
	ground->CreateFixture(&shape, 5.0f);
	shape.Set(b2Vec2(0.0f, 0.0f), b2Vec2(0.0f, h / SCALE));
	ground->CreateFixture(&shape, 5.0f);
	shape.Set(b2Vec2(w / SCALE, 0.0f), b2Vec2(w / SCALE, h / SCALE));
	ground->CreateFixture(&shape, 5.0f);
	shape.Set(b2Vec2(0.0f, h / SCALE), b2Vec2(w / SCALE, h / SCALE));
	ground->CreateFixture(&shape, 5.0f);
}

/// <Summary>
/// Cleans up resources the Box 2d simulation uses.
/// </Summary>
Box2dSimulation::~Box2dSimulation()
{
	world->DestroyBody(ground);
	delete world;
}

/// <Summary>
/// Steps the simulation forward.
/// </Summary>
void Box2dSimulation::step()
{
	world->Step(1.0f / 60.0f, 8, 3);
}

/// <Summary>
/// Adds a new BSprite object
/// </Summary>
void Box2dSimulation::add(int pokemon, float32 x, float32 y)
{
	BSprite *temp = new BSprite(world, pokemon, x, y);
	bSprites.push_back(temp);
}

std::vector<BSprite*> Box2dSimulation::getBSprites()
{
	return bSprites;
}
