#include "Renderer/Renderer.h"

Renderer::Renderer() : window(nullptr), renderer(nullptr), font(nullptr){}

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

    if(!TTF_Init()) return false;

    font = TTF_OpenFont("../assets/fonts/font.ttf", FONTSIZE);
    if(font == nullptr) return false;

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
    DrawTextOnScreen("Count: "+std::to_string( + world.GetBodyCount()), 100.0f, 100.0f);
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

void Renderer::DrawTextOnScreen(std::string text, float x, float y)
{
    // needs optimization

    if(!font || !renderer) return;
    SDL_Color fontColor = {F_R, F_G, F_B, F_A};
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), 0, fontColor);
    if(!surface) return;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    if(!texture)
    {
        SDL_DestroySurface(surface);
        return;
    }
    SDL_FRect destRect = { x, y, (float)surface->w, (float)surface->h };   
    SDL_DestroySurface(surface);
    SDL_RenderTexture(renderer,texture,nullptr,&destRect);
    SDL_DestroyTexture(texture);
}