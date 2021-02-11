#ifndef SNAILIDLESTATE_H
#define SNAILIDLESTATE_H
#include "Snail.h"
#include "PlayScreen.h"

class SnailIdleState:public Collision
{
    public:
        enum SNAILSTATES{idleS,moving,chasing};
        SnailIdleState();
        virtual ~SnailIdleState();
void idleAnimation(Snail&snail);
void Update(PlayScreen&mPlayScreen,Snail&snail);
float mAnimationTimer=0.2f;
int count=0;
bool startanim=false;

        Timer* mTimer;
    private:
};

#endif // SNAILIDLESTATE_H
