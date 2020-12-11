#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"
#include "Collision.h"
#include "Score.h"
#include "Countdown.h"
#include "BackPlane.h"
#include "SDL2SoundEffets.h"
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
    Score*scoreState;
    Countdown*mCountScreen;
    BackPlane*mBacplane;
    //SDL2SoundEffets *sound;
    AudioManager* mAudioMgr;
    bool setvalue=false;
    bool scrolling = true;
    public:
        static ScreenManager*Instance();
        static void Release();
        void Update();
        void Render();
int scoreValue=0;

    private:
        ScreenManager();
        ~ScreenManager();
};

#endif // SCREENMANAGER_H
