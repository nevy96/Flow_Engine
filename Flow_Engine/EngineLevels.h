#include "Box2D.h"
//TEST LEVEL
const float SCALE = 30.f;

void CreateGround(b2World& World, float X, float Y)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(X/30.f, Y/30.f);
    BodyDef.type = b2_staticBody;
    b2Body* Body = World.CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((800.f/2)/SCALE, (16.f/2)/SCALE); // Creates a box shape. Divide your desired width and height by 2.
    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.f;  // Sets the density of the body
    FixtureDef.shape = &Shape; // Sets the shape
    Body->CreateFixture(&FixtureDef); // Apply the fixture definition
}

void CreateBox(b2World& World, int MouseX, int MouseY)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(MouseX/SCALE, MouseY/SCALE);
    BodyDef.type = b2_dynamicBody;
    b2Body* Body = World.CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((32.f/2)/SCALE, (32.f/2)/SCALE);
    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
}