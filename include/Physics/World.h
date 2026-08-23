#pragma once

#include <vector>

#include "Physics/Body.h"

class World
{
public:
    float width, height;
    Vector2 gravity;
    std::vector<Body> bodies;// list of all objects spawned

    World(float w, float h);
    void AddBody(const Body& body);
    void Update(float dt); // elapsed time
private:
    void CheckBoundaries(Body &b);
    void ResolveCollission(); // will implement this later
};