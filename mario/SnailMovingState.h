#ifndef SNAILMOVINGSTATE_H
#define SNAILMOVINGSTATE_H
#include "Timer.h"
#include "Collision.h"
#include "Snail.h"
#include "PlayScreen.h"

using namespace std;
class SnailMovingState:public Collision
{
    public:
        enum DIRECTION{left,right};
        SnailMovingState();
        virtual ~SnailMovingState();
void movinAnimation(Snail&snail);
void Update(PlayScreen&mPlayScreen,Snail&snail);
bool checkLeftCollisions(PlayScreen&mPlayScreen,Snail&snail,int ex);
bool checkRightCollisions(PlayScreen&mPlayScreen,Snail&snail,int ex);
void Reset(Snail&snail);
float mAnimationTimer=0.2f;
int count=0;
bool startanim=false;

        Timer* mTimer;
int movingDuration=0;
float movingTimer=0;
    private:
};

#endif // SNAILMOVINGSTATE_H
