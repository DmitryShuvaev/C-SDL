#ifndef PLAYERFALLINGSTATE_H
#define PLAYERFALLINGSTATE_H
#include "Collision.h"
#include "PlayScreen.h"
#include "InputManager.h"
class PlayerFallingState:public Collision
{
    public:
        PlayerFallingState();
        virtual ~PlayerFallingState();

void Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen);
InputManager*mInput;
    private:
};

#endif // PLAYERFALLINGSTATE_H
