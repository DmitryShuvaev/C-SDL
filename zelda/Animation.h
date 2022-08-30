#ifndef ANIMATION_H
#define ANIMATION_H
#include "Player.h"
#include "Timer.h"

class Animation
{
    public:
        enum STATES{left,right,up,down,idle,SwordLeft};
        Animation();
        void Reset();
        virtual ~Animation();

    void movinAnimation_Left(Player&mcharacter);
    void movinAnimation_Right(Player&mcharacter);
    void movinAnimation_Up(Player&mcharacter);
    void movinAnimation_Up_dungeon(Player&mcharacter);
    void movinAnimation_Down(Player & mcharacter);
    void setIdle(Player & mcharacter);

float mAnimationTimer=0.2f;
int count=0;
bool startanim=false;

        Timer* mTimer;
Timer* mgemTimeanim;
float mgemAnimationTimer=0.0f;
//int gemcounter=0;
STATES curentanim;
bool anim_start=false;
};

#endif // ANIMATION_H
