#include "Renderer/Renderer.h"

Renderer::Renderer() : window(nullptr), renderer(nullptr) {}

Renderer::~Renderer()
{
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Renderer::Init(const char* title, int width, int height)
{
    if(!SDL_Init(SDL_INIT_VIDEO)) return false;
    
    window = SDL_CreateWindow(title, width, height, 0);
    if(!window) return false;
    
    renderer = SDL_CreateRenderer(window, nullptr);
    if(!renderer) return false;

    return true;
}

void Renderer::Clear()
{
    SDL_SetRenderDrawColor(renderer, 18, 22, 28, 255);
    SDL_RenderClear(renderer);
}

void Renderer::Render()
{
    SDL_RenderPresent(renderer);
}

void Renderer::DrawWorld(const World &world)
{
    SDL_SetRenderDrawColor(renderer, 240, 180, 70, 255);
    for(const auto& body : world.bodies)
    {
        DrawCircle(body.pos.x, body.pos.y, body.radius);
    }
}

/*
* Copied ts straight off the web, should work, all i know is its rendering the circle in 8 octets
*/
void Renderer::DrawCircle(float cx, float cy, float radius)
{
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius * 2);

    while(x > y)
    {
        SDL_RenderPoint(renderer, cx+x, cy+y);
        SDL_RenderPoint(renderer, cx+y, cy+x);
        SDL_RenderPoint(renderer, cx-y, cy+x);
        SDL_RenderPoint(renderer, cx-x, cy+y);
        SDL_RenderPoint(renderer, cx-x, cy-y);
        SDL_RenderPoint(renderer, cx-y, cy-x);
        SDL_RenderPoint(renderer, cx+y, cy-x);
        SDL_RenderPoint(renderer, cx+x, cy-y);

        if(err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }

        if(err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius * 2);
        }
    }
}