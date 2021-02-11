#ifndef ANIMATION_H
#define ANIMATION_H
#include "Character.h"
#include "Timer.h"

class Animation
{
    public:
        Animation();
        void Reset();
        virtual ~Animation();

    void movinAnimation(Character&mcharacter);
    void jumpAnimation(Character&mcharacter);
    void gemAnimation(int &y);
float mAnimationTimer=0.2f;
int count=0;
bool startanim=false;
    private:
        Timer* mTimer;
Timer* mgemTimeanim;
float mgemAnimationTimer=0.0f;
int gemcounter=0;

};

#endif // ANIMATION_H
