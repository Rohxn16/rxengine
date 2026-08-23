#pragma once
#include "Physics/World.h"

#include <SDL3/SDL.h>

class Renderer
{

    SDL_Window*     window;
    SDL_Renderer*   renderer;
    void DrawCircle(float cx, float cy, float radius);

public:
    Renderer();
    ~Renderer();

    bool Init(const char* title, int width, int height);
    void Clear();
    void DrawWorld(const World &world);
    void Render();
};
