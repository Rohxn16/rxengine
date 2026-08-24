#pragma once

#include <vector>

#include "Physics/CircleBody.h"

class World
{
public:
    float width, height;
    Vector2 gravity;
    std::vector<CircleBody> bodies;// list of all objects spawned

    World(float w, float h);
    void AddBody(const CircleBody& body);
    void Update(float dt); // elapsed time
private:
    void CheckBoundaries(CircleBody &b);
    void ResolveCollission(); // will implement this later
};