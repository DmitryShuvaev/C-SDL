#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Graphics.h"
#include "ScreenManager.h"
#include "Timer.h"
#include <time.h>
#include <sstream>
#include <cmath>
//#include <SDL.h>
// How many frames time values to keep
// The higher the value the smoother the result is...
// Don't make it 0 or less :)
#define FRAME_VALUES 30
//The application time based timer
class LTimer
{
    public:
		//Initializes variables
LTimer()
{

}

// An array to store frame times:
Uint32 frametimes[FRAME_VALUES];

// Last calculated SDL_GetTicks
Uint32 frametimelast;

// total frames rendered
Uint32 framecount;

// the value you want
float framespersecond;

// This function gets called once on startup.
void fpsinit() {

        // Set all frame times to 0ms.
        memset(frametimes, 0, sizeof(frametimes));
        framecount = 0;
        framespersecond = 0;
        frametimelast = SDL_GetTicks();

}

void fpsthink() {

        Uint32 frametimesindex;
        Uint32 getticks;
        Uint32 count;
        Uint32 i;

        // frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
        // This value rotates back to 0 after it hits FRAME_VALUES.
        frametimesindex = framecount % FRAME_VALUES;

        // store the current time
        getticks = SDL_GetTicks();

        // save the frame time value
        frametimes[frametimesindex] = getticks - frametimelast;

        // save the last frame time for the next fpsthink
        frametimelast = getticks;

        // increment the frame count
        framecount++;

        // Work out the current framerate

        // The code below could be moved into another function if you don't need the value every frame.

        // I've included a test to see if the whole array has been written to or not. This will stop
        // strange values on the first few (FRAME_VALUES) frames.
        if (framecount < FRAME_VALUES) {

                count = framecount;

        } else {

                count = FRAME_VALUES;

        }

        // add up all the values and divide to get the average frame time.
        framespersecond = 0;
        for (i = 0; i < count; i++) {

                framespersecond += frametimes[i];

        }

        framespersecond /= count;

        // now to make it an actual frames per second value...
        framespersecond = 1000.f / framespersecond;

}
};//
//



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
        //In memory text stream
			std::stringstream timeText;
         float avfps=0.f;
            Texture *gFPSTextTexture;
            //The frames per second timer

};

#endif // GAMEMANAGER_H
