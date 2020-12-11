#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>
class Graphics
{
public:
    static const int SCREEN_WIDTH=1280;
    static const int SCREEN_HEIGHT=720;
    const char*WINDOW_TITLE="Fifty Bird";
    static bool sInitialized;
    public:
        Graphics();
       SDL_Texture*CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);
       void DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip);
       void DrawTexture(SDL_Texture* tex,SDL_Rect &p);
        void drawMenuTex(SDL_Surface* menu,SDL_Rect &p);
        SDL_Texture* LoadTexture(std::string path);
        void ClearBackBuffer();
        ~Graphics();
    static Graphics*Instance();
    static void Release();
    void Render();
    void RenderRect(SDL_Rect mRenderRect,SDL_Color color);
    private:
        bool Init();
    public:
        static Graphics*sInstance;
        SDL_Window*mWindow;
        SDL_Renderer*mRenderer;

};

#endif // GRAPHICS_H
