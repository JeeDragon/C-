#include "Box2dSimulation.h"
#include <Box2D\Box2D.h>
#include "BSprite.h"
#include "BSpriteContactListener.h"

/// <Summary>
/// Constructs a new Box 2d Simulation.
/// </Summary>
Box2dSimulation::Box2dSimulation()
{
	b2Vec2 gravity(0.0f, 9.8f);
	world = new b2World(gravity);
	world->SetContactListener(listener);

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

	BSprite* pokedex = new BSprite(world, 6, b2_staticBody, 100, 150);
	bSprites.push_back(pokedex);

	//b2BodyDef pokedexDef;
	//pokedexDef.type = b2_staticBody;
	//pokedexDef.position.Set(200 / SCALE, 200 / SCALE);

	//b2PolygonShape box;
	//box.SetAsBox(2, 3);

	//b2Body* pokedex = world->CreateBody(&pokedexDef);
	//b2FixtureDef pokedexFix;
	//pokedexFix.shape = &box;
	//pokedex->CreateFixture(&pokedexFix);

	//sf::Texture* pokedexTexture = new sf::Texture();
	//pokedexTexture->loadFromFile("../resources/battery.png");
	//sf::Sprite* pokedexSprite = new sf::Sprite();
	//pokedexSprite->setTexture((*pokedexTexture));
	//pokedexSprite->setPosition(200, 300);
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
	BSprite *temp = new BSprite(world, pokemon, b2_dynamicBody, x, y);
	bSprites.push_back(temp);
}

std::vector<BSprite*> Box2dSimulation::getBSprites()
{
	return bSprites;
}

//void Box2dSimulation::BeginContact(b2Contact * contact)
//{
//}
//
//void Box2dSimulation::EndContact(b2Contact * contact)
//{
//	std::cout << "end contact" << std::endl;
//}
//
//void Box2dSimulation::PreSolve(b2Contact * contact, const b2Manifold * oldManifold)
//{
//	if (contact->IsTouching())
//	{
//		b2Fixture* fixture = contact->GetFixtureA();
//		b2Body* body = fixture->GetBody();
//		std::vector<BSprite*>::iterator iter;
//		for (iter = bSprites.begin(); iter != bSprites.end(); iter++)
//		{
//			BSprite* bS = (*iter);
//			if (bS->equal(body))
//			{
//				bS->playSound(0);
//				break;
//			}
//			delete bS;
//		}
//	}
//}
//
//void Box2dSimulation::PostSolve(b2Contact * contact, const b2ContactImpulse * impulse)
//{
//}
