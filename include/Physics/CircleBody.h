#pragma once
#include "Math/Vector2.h"

/*
* Considering body to be round object only for now, 
* the vision is to also include square bodies as well
*/

struct CircleBody
{
    Vector2 pos;
    Vector2 vel;
    float   mass;
    float   radius;
    float   restitution;
};