#ifndef BSPRITECONTACTLISTENER_H
#define BSPRITECONTACTLISTENER_H
#include <Box2D\Box2D.h>
#include "BSprite.h"

class BSpriteContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* b2Contact)
	{
		//check if fixture A was a ball
		void* bodyUserData = b2Contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<BSprite*>(bodyUserData)->startContact();

		//check if fixture B was a ball
		bodyUserData = b2Contact->GetFixtureB()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<BSprite*>(bodyUserData)->startContact();
	}

	void EndContact(b2Contact* b2Contact)
	{
		//check if fixture A was a ball
		void* bodyUserData = b2Contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<BSprite*>(bodyUserData)->startContact();

		//check if fixture B was a ball
		bodyUserData = b2Contact->GetFixtureB()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<BSprite*>(bodyUserData)->startContact();
	}
};
#endif
