#ifndef PLAYERIDLESTATE_H
#define PLAYERIDLESTATE_H
#include "Collision.h"
#include "PlayScreen.h"
#include "InputManager.h"
#include "PlayerSwingSwordState.h"
class PlayerIdleState:public Collision
{
    public:
        PlayerIdleState();
        virtual ~PlayerIdleState();

void Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen,PlayerSwingSwordState&mSwordScreen);
InputManager*mInput;
AudioManager* mAudioMgr;

};

#endif // PLAYERIDLESTATE_H
