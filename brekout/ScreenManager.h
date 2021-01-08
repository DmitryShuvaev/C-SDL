#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"
#include "ServeScreen.h"
#include "Collision.h"
#include "Background.h"
#include "AudioManager.h"
#include "Health.h"
#include "GameOverScreen.h"
#include "VictoryScreen.h"
#include "HighScoreScreen.h"
#include <sstream>
#include <iostream>
#include <fstream>

class ScreenManager:public Collision
{
private:

    static ScreenManager*sInstance;



    public:

    SCREENS mCurrentScreen;
    InputManager*mInput;
    StartScreen*mStartScreen;
    PlayScreen*mPlayScreen;
    ServeScreen*mServeScreen;
    GameOverScreen*mGameOverScreen;
    VictoryScreen*mVictoryScreen;
    HighScoreScreen*mHighScoreScreen;
    Health *health;
    Texture*mscore;
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
        void Readfromfile();
        void WriteToFile();
    int scoreValue=0;
    int prevscore=0;
    int level=1;
    HighScores mHighScores[10];
    private:
        ScreenManager();
        ~ScreenManager();
         Background*background;
};

#endif // SCREENMANAGER_H
