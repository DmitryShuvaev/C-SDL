#ifndef TEXTURE_H
#define TEXTURE_H

#include "Graphics.h"

class Texture
{
    public:
        Texture();
        Texture(char* fontname,char* text,int SIZE,SDL_Color color);
        Texture(std::string filename);
        void SetXY(float x,float y);
        void Render();
        void RenderFlipped();
        void SetColor(SDL_Color color);
        void SetPos(int x,int y);
        void SetText(char* text);
        void RenderRec(SDL_Color color);
         ~Texture();

    protected:

    private:
        TTF_Font* font;
        char* text;
    public:
        //True if the texture is loaded from a spritesheet
		bool mClipped;
        SDL_Texture*mTex;
        Graphics*mGraphics;
        int mWidth;
        int mHeight;
        SDL_Rect mRenderRect;
        SDL_Rect mClipRect;
        SDL_Color color;
};

#endif // TEXTURE_H
