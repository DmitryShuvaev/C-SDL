#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Graphics.h"
#include "ScreenManager.h"
#include "Timer.h"
#include <time.h>
//#include <SDL.h>

class GameManager
{
    public:
        static GameManager*Instance();
        static void Release();
        void Run();
    private:
        GameManager();
        ~GameManager();
        void Update();
        void EarlyUpdate();
        void LateUpdate();
        void Render();

    private:
        static GameManager*sInstance;
        ScreenManager*mScreenMgr;
        const int FRAME_RATE=60;
        Graphics*mGraphics;
        SDL_Event mEvents;
        InputManager*mInputMgr;
        bool mQuit;
        Timer* mTimer;
};

#endif // GAMEMANAGER_H
