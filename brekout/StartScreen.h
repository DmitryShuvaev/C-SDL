#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Texture.h"
#include <iostream>
#include "InputManager.h"
#include "Collision.h"
#include <vector>
#include <memory>
#include "AudioManager.h"
using namespace std;
class StartScreen:public Collision
{
    public:
        StartScreen();
        ~StartScreen();

        void Update(SCREENS &mCurrentScreen);
        void Render();

    protected:
const int FONT_SIZE=32*3;
    //SDL_Color color[4] = {{255,255,255},{255,0,0},{175,53,42},{34,34,34}};

        public:

        InputManager*mInput;

        Texture*title;
        Texture*start;
        Texture*highScore;
        //whether we're highlighting "Start" or "High Scores"
        int highlighted = 1;
        bool ifHighlited=false;
        AudioManager* mAudioMgr;
};

#endif // STARTSCREEN_H
