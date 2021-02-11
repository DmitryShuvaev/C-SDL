#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include "Graphics.h"
#include <sstream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
class Texture
{
    public:
        Texture();
        Texture(char* fontname,char* text,int SIZE,SDL_Color color);
        Texture(std::string filename);
        void SetXY(float x,float y);
        void SetColor(SDL_Color color);
        void SetText(std::string text,SDL_Color color);
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip ,float Scalex,float Scaley );
		void Render();
		void setAlpha( Uint8 alpha );
         ~Texture();

    public:
        TTF_Font* font;
        char* text;
        SDL_Texture*mTex;
        Graphics*mGraphics;
        int mWidth;
        int mHeight;
        SDL_Rect mRenderRect;
};

#endif // TEXTURE_H
