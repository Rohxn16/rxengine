#include <iostream>
#include <random>

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
    static thread_local std::random_device rd;
    static thread_local std::mt19937 generator(rd());

  while(running)
  {
    size_t body_count = myWorld.GetBodyCount();
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_EVENT_QUIT)
        running = false;
      
      // check mouse button click and spawn a body from there
      // TODO: implement Click and hold for constant generation
      if(event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
      {
          float X = event.button.x;
          float Y = event.button.y;
          std::uniform_real_distribution<float> distribution(0.0, 1.0);
          myWorld.AddBody({Vector2(X,Y), Vector2(150, 0), 10.0f, distribution(generator)*100.0f, distribution(generator) });
      }

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