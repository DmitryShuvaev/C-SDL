#ifndef COUNTDOWN_H
#define COUNTDOWN_H
#include "Texture.h"
#include "Collision.h"
#include "Timer.h"
#include <iostream>
#include <cstring>
using namespace std;
class Countdown:public Collision
{
    public:
        Countdown();
        virtual ~Countdown();
        void Update(SCREENS &mCurrentScreen,bool &scrolling) ;
        void Render();
        void Reset();
Timer* mTimer;
float mAnimationSpeed=1.f;
float mAnimationTimer=1.f;
SDL_Color color[2] = {{255,255,255},{255,0,0}};
float ic=2.5;
int count=3;
Texture*mCountText;
    private:
};

#endif // COUNTDOWN_H
