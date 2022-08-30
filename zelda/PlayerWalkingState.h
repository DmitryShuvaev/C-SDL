#ifndef PLAYERWALKINGSTATE_H
#define PLAYERWALKINGSTATE_H
#include "Collision.h"
#include "PlayScreen.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Dungeon.h"
class PlayerWalkingState:public Collision
{
    public:
        PlayerWalkingState();
        virtual ~PlayerWalkingState();
        void collision_detection_up(SCREENS &mCurrentScreen,Room&room,PlayScreen&mPlayScreen);
        void collision_detection_low(SCREENS &mCurrentScreen,Room&room,PlayScreen&mPlayScreen);
        void collision_detection_left(SCREENS &mCurrentScreen,Room&room,PlayScreen&mPlayScreen);
        void collision_detection_right(SCREENS &mCurrentScreen,Room&room,PlayScreen&mPlayScreen);
void Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen);
InputManager*mInput;
AudioManager* mAudioMgr;
};

#endif // PLAYERWALKINGSTATE_H
