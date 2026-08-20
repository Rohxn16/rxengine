#include <iostream>
#include "vec2.hpp"

int main()
{
  
  vec2 p1 = {10,20};
  vec2 p2 = {20,10};

  std::cout << vec2::getDistance(p1,p2) << std::endl;
  
  return 0;
}