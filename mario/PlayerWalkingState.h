#ifndef PLAYERWALKINGSTATE_H
#define PLAYERWALKINGSTATE_H
#include "Collision.h"
#include "PlayScreen.h"
#include "InputManager.h"

class PlayerWalkingState:public Collision
{
    public:
        PlayerWalkingState();
        virtual ~PlayerWalkingState();

void Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen);
InputManager*mInput;
    private:
};

#endif // PLAYERWALKINGSTATE_H
