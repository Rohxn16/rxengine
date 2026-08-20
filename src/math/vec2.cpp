#include "vec2.hpp"
#include <cmath>

vec2::vec2()
{
  this->m_x = 0.0F;
  this->m_x = 0.0F;
}

vec2::vec2(const float &x, const float &y)
{
  this->m_x = x;
  this->m_y = y;
}

vec2::~vec2()
{

}

float vec2::dotProduct(const vec2 &x, const vec2 &y)
{
  return (x.m_x*y.m_x) + (x.m_y*y.m_y);
}

float vec2::crossProduct(const vec2 &a, const vec2 &b)
{
  return (a.m_x*b.m_x) - (a.m_y*b.m_y);
}

float vec2::getDistance(const vec2 &a, const vec2 &b)
{
  return sqrtf64(
    ((a.m_x-b.m_x)*(a.m_x-b.m_x)) + 
    ((a.m_y-b.m_y)*(a.m_y-b.m_y))
  );
}