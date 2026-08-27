#pragma once
#include "Physics/World.h"
#include "base.h"

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

class Renderer
{

    SDL_Window*     window;
    SDL_Renderer*   renderer;
    TTF_Font*       font;
    void DrawCircle(float cx, float cy, float radius);
    void DrawTextOnScreen(std::string text, float X, float Y);

public:
    Renderer();
    ~Renderer();

    bool Init(const char* title, int width, int height);
    void Clear();
    void DrawWorld(const World &world);
    void Render();
};
