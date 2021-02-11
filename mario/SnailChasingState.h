#ifndef SNAILCHASINGSTATE_H
#define SNAILCHASINGSTATE_H
#include "Snail.h"
#include "PlayScreen.h"

class SnailChasingState:public Collision
{
    public:
        SnailChasingState();
        virtual ~SnailChasingState();

void Update(PlayScreen&mPlayScreen,Snail&snail);
bool checkLeftCollisions(PlayScreen&mPlayScreen,Snail&snail,int ex);
bool checkRightCollisions(PlayScreen&mPlayScreen,Snail&snail,int ex);
    private:
};

#endif // SNAILCHASINGSTATE_H
