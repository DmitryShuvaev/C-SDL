#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include <vector>
#include <iostream>
#include <memory>
#include "Bird.h"
#include "Collision.h"
#include <cstring>
using namespace std;
#define PI 3.14159265358979323846
class PlayScreen:public Collision
{
    public:
        PlayScreen();
        void init();
 void drawMenuTex(SDL_Surface* menu,SDL_Rect &p);
        void Update(SCREENS &mCurrentScreen,int &score,bool &scrolling);
        void Render();
        bool colidecontinue();
        bool colideexit();
        void ClearScreen();
        ~PlayScreen();
        char*conveText(std::string scoreStr);
    protected:

    private:

    const int SIZE=16;
    SDL_Color color[2] = {{255,255,255},{255,0,0}};
    const int FONT_SIZE=32;
    const float GRAVITY = 0.2;
    float spawnTimer=0;
    float dy=1;
    float ic=2.5;
    int scoreValue=0;
    int BACKGROUND_LOOPING_POINT = -413*ic;
    float BACKGROUND_SCROLL_SPEED = 0.5;
    float GROUND_SCROLL_SPEED = 1;
    float backgroundScroll=0;
    float groundScroll=0;
    bool scrolling=true;
        public:

//        Texture*background;
//        Texture*ground;
        Texture*scoreTex;
        Bird*bird;
        AudioManager* mAudioMgr;
        InputManager*mInput;
        std::vector<std::unique_ptr<Tube>> pipes;
};

#endif // PLAYSCREEN_H
