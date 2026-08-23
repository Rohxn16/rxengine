#include <iostream>

#include "Renderer/Renderer.h"
#include "Physics/World.h"
#include "base.h"

int main()
{

  std::cout << "Hello, World\n";

  /*
  * Vector operations are working
  
    Vector2 a(10,20);
    Vector2 b(-1,12);
  
    std::cout << a.Length() << std::endl;
    std::cout << a.Dot(b) << std::endl;
    Vector2 v = a + b;
    std::cout << "a: " << v.x << "b: " << v.y << std::endl;
    v = a - b;
    std::cout << "a: " << v.x << "b: " << v.y << std::endl;
    float scalar = 4.5f;
    v = a * scalar ;
    std::cout << "a: " << v.x << "b: " << v.y << std::endl;
  */

  // lets test our basic engine out

  Renderer renderer;
  if(!renderer.Init("rxengine - SDL3 edition", WIDTH, HEIGHT)) return -1;
  
  World myWorld(WIDTH,HEIGHT);
  myWorld.AddBody({Vector2(400,100), Vector2(150, 0), 10.0f, 30.0f, 0.8f});
  myWorld.AddBody({Vector2(450,300), Vector2(-50, -200), 15.0f, 40.0f, 0.9f});
  myWorld.AddBody({Vector2(350, 400), Vector2(0, -100), 5.0f, 20.0f, 0.6f});

  bool running = true;
  SDL_Event event;

  Uint64 prevTime = SDL_GetTicks();
  const float dt = 1.0f/60.0f;

  while(running)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_EVENT_QUIT)
        running = false;
    }
    Uint64 currTime = SDL_GetTicks();
    float frameTime = (currTime - prevTime) / 1000.0f;
    prevTime = currTime;

    myWorld.Update(dt);
    renderer.Clear();
    renderer.DrawWorld(myWorld);
    renderer.Render();

    SDL_Delay(16);
  }
  return 0;
}