#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"
#include "Collision.h"
#include "PlayerWalkingState.h"
#include "PlayerIdleState.h"
#include "PlayerSwingSwordState.h"
#include "EntityWalkState.h"
#include "EntityIdleState.h"
#include "GameOverState.h"
#include "AudioManager.h"
class ScreenManager:public Collision
{
private:

    static ScreenManager*sInstance;



    public:

    SCREENS mCurrentScreen;
    InputManager*mInput;
    StartScreen*mStartScreen;
    PlayScreen*mPlayScreen;
    PlayerWalkingState*mPlayerWalkingState;
    PlayerIdleState*mPlayerIdleState;
    PlayerSwingSwordState*mPlayerSwingSwordState;
    EntityWalkState*mEnemyEntityWalkState;
    EntityIdleState*mEnemyEntityIdleState;
    GameOverState*mGameOverState;
    //SDL2SoundEffets *sound;
    AudioManager* mAudioMgr;
    bool setvalue=false;
    bool scrolling = true;
    public:
        static ScreenManager*Instance();
        static void Release();
        void Update();
        void Render();
//int scoreValue=0;

    private:
        ScreenManager();
        ~ScreenManager();
};

#endif // SCREENMANAGER_H
