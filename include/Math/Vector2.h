#pragma once

#include <cmath>

/*
Considering struct instead of class since data members here are public regardless
*/
struct Vector2
{
    float x;
    float y;

    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
    Vector2 operator-(const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
    Vector2 operator*(float scalar)     const { return Vector2(x * scalar, y * scalar); }

    float Dot(const Vector2 &v) const {return x * v.x + y * v.y; };
    float Length() const { return std::sqrt(x * x + y * y); }
    Vector2 Normalized() const {
        float len = Length();
        return (len > 0.0f) ? Vector2(x/len, y/len) : Vector2(0,0);
    }
};
