#ifndef BOX2DSIMULATION_H
#define BOX2DSIMULATION_H

#include <Box2D\Box2D.h>
#include "BSprite.h"

class Box2dSimulation
{
public:
	Box2dSimulation();
	~Box2dSimulation();
	void step();
	void add(int, float32, float32);
	std::vector<BSprite*> getBSprites();
private:
	b2World* world;
	b2Body* ground;
	const float SCALE = 30.0f;
	std::vector<BSprite*> bSprites;
};

#endif
