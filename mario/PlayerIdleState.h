#ifndef PLAYERIDLESTATE_H
#define PLAYERIDLESTATE_H
#include "Collision.h"
#include "PlayScreen.h"
#include "InputManager.h"

class PlayerIdleState:public Collision
{
    public:
        PlayerIdleState();
        virtual ~PlayerIdleState();

void Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen);
InputManager*mInput;

    private:
};

#endif // PLAYERIDLESTATE_H
