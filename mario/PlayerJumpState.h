#ifndef PLAYERJUMPSTATE_H
#define PLAYERJUMPSTATE_H
#include "Collision.h"
#include "PlayScreen.h"
#include "InputManager.h"

class PlayerJumpState:public Collision
{
    public:
        PlayerJumpState();
        virtual ~PlayerJumpState();

void Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen);
InputManager*mInput;

    private:
};

#endif // PLAYERJUMPSTATE_H
