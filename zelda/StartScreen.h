#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Texture.h"
#include <iostream>
#include "InputManager.h"
#include "PlayScreen.h"
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
        void Update(SCREENS &mCurrentScreen,PlayScreen*mPlayScreen);
        void Render();

    protected:

    SDL_Color color[4] = {{255,255,255},{255,0,0},{175,53,42},{34,34,34}};

        public:
        Texture*background;
        Texture*title;
        Texture*titlelow;
        Texture*presEnter;
        InputManager*mInput;
};

#endif // STARTSCREEN_H
