#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"
#include "PlayerJumpState.h"
#include "Collision.h"
#include "PlayerWalkingState.h"
#include "AudioManager.h"
#include "PlayerFallingState.h"
#include "PlayerIdleState.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "SnailMovingState.h"
#include "SnailIdleState.h"
#include "SnailChasingState.h"

class ScreenManager:public Collision
{
private:

    static ScreenManager*sInstance;



    public:
    enum SNAILSTATES{idleS,moving,chasing};
    SCREENS mCurrentScreen;
    InputManager*mInput;
    StartScreen*mStartScreen;
    PlayScreen*mPlayScreen;
    PlayerFallingState*mPlayerFallingState;
    PlayerWalkingState*mPlayerWalkingState;
    PlayerIdleState*mPlayerIdleState;
    PlayerJumpState*mPlayerJumpState;
     SnailMovingState*smoveanim;
     SnailIdleState*msnailIdlestate;
     SnailChasingState*msnailChaisestate;
    std::stringstream scoreText;
    //SDL2SoundEffets *sound;
    AudioManager* mAudioMgr;
   // bool setvalue=false;
    bool scrolling = true;
    public:
        static ScreenManager*Instance();
        static void Release();
        void Update();
        void Render();

    int scoreValue=3050;
    int prevscore=0;
    int level=1;
    int highScoreIndex=0;

    private:
        ScreenManager();
        ~ScreenManager();

};

#endif // SCREENMANAGER_H
