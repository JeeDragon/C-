#ifndef BOX2DSIMULATION_H
#define BOX2DSIMULATION_H

#include <Box2D\Box2D.h>
#include "BSprite.h"
#include "BSpriteContactListener.h"

class Box2dSimulation
{
public:
	Box2dSimulation();
	~Box2dSimulation();
	void step();
	void add(int, float32, float32);
	std::vector<BSprite*> getBSprites();
private:
	BSpriteContactListener* listener;
	//virtual void BeginContact(b2Contact* contact);
	//virtual void EndContact(b2Contact* contact);
	//virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	//virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

	//b2ContactListener* listener;
	b2World* world;
	b2Body* ground;
	const float SCALE = 30.0f;
	std::vector<BSprite*> bSprites;
};

#endif
