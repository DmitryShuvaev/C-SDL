#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Texture.h"
#include <iostream>
#include "InputManager.h"
#include "Collision.h"
#include <vector>
#include <memory>
//#include "Bird.h"
using namespace std;
class StartScreen:public Collision
{
    public:
        StartScreen();
        ~StartScreen();
        void drawMenuTex(SDL_Surface* menu,SDL_Rect &p);
        void Update(SCREENS &mCurrentScreen);
        void Render();
        bool colidecontinue();
        bool colideexit();
    protected:

    private:

    const int SIZE=16;
    SDL_Color color[2] = {{255,255,255},{255,0,0}};
    const int FONT_SIZE=32;
    const float GRAVITY = 0.2;
    float spawnTimer=0;
    float dy=1;
    float ic=2.5;
    int BACKGROUND_LOOPING_POINT = -413*ic;
    float BACKGROUND_SCROLL_SPEED = 0.5;
    float GROUND_SCROLL_SPEED = 1;
    float backgroundScroll=0;
    float groundScroll=0;
    bool scrolling=true;
        public:
        Texture*continueText;
        Texture*exitText;

        Texture*title;
        Texture*presEnter;
        InputManager*mInput;

};

#endif // STARTSCREEN_H
