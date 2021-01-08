#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include <vector>
#include <iostream>
#include <memory>
#include "Texture.h"
#include "Collision.h"
#include "AudioManager.h"
#include <cstring>
#include "InputManager.h"
#include "Paddle.h"
#include "Ball.h"
#include "LevelMaker.h"
#include "Health.h"
using namespace std;
#define PI 3.14159265358979323846
class PlayScreen:public Collision
{
    public:
        PlayScreen();
//        void init();

        void Update(SCREENS &mCurrentScreen,int &score,Health &health,int&level);
        void Render();
        void clearScreen();
        bool checkVictory();
        ~PlayScreen();
        //char*conveText(std::string scoreStr);
    protected:

    private:

    const int SIZE=16;
    SDL_Color color[2] = {{255,255,255},{255,0,0}};

        public:
        Texture *pause;
        AudioManager* mAudioMgr;
        InputManager*mInput;
        SDL_Rect gSpriteClips;
        Paddle *padlle;
        bool paused=false;
        Ball *ball;
LevelMaker *lmaker;
};

#endif // PLAYSCREEN_H
