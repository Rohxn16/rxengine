#include "Physics/Body.h"
#include "Physics/World.h"

#include <iostream>

World::World(float w, float h) : gravity(0.0f, 980), width(w), height(h) {}

void World::AddBody(const Body &body)
{
    bodies.push_back(body);
}

void World::Update(float dt)
{
    for (auto &body : bodies)
    {
        body.vel = body.vel + gravity * dt; // did not overload += so that wont work, whatever
        body.pos = body.pos + body.vel * dt;
        CheckBoundaries(body);
    }

    // resolve collission if any
    ResolveCollission();
}

void World::CheckBoundaries(Body &body)
{
    // x axis collission check
    if(body.pos.x - body.radius < 0)
    {
        body.pos.x = body.radius;
        body.vel.x *= -body.restitution; // adds bounce to the circle to the opposite direction
    } else if (body.pos.x + body.radius > width)
    {
        body.pos.x = width - body.radius;
        body.vel.x *= -body.restitution;
    }

    // y axis collission check

    if(body.pos.y - body.radius < 0)
    {
        body.pos.y = body.radius;
        body.vel.y *= -body.restitution; // adds bounce to the circle to the opposite direction
    } else if (body.pos.y + body.radius > height)
    {
        body.pos.y = height - body.radius;
        body.vel.y *= -body.restitution;
    }

}

void World::ResolveCollission()
{
    /*
    * Will resolve this later, need to read up on this.
    */
    std::cout << "Collission Resolver called" << std::endl;
}