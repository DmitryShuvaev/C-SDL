#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include <vector>
#include <iostream>
#include <memory>
#include "Texture.h"
#include "Collision.h"
#include "AudioManager.h"
#include <cstring>
#include "InputManager.h"
#include "Room.h"
#include "Player.h"
#include "Animation.h"
#include "Dungeon.h"
using namespace std;
#define PI 3.14159265358979323846
struct Heart_obj
{
        SDL_Rect heart_rect;
        int x;
        int y;
};
class PlayScreen:public Collision
{
    public:
        PlayScreen();
        void init();
// void drawMenuTex(SDL_Surface* menu,SDL_Rect &p);
        void Update(SCREENS &mCurrentScreen);
        void Render();
        void moveLeft_Right(int positionx);
        void moveUp_Down(int positiony);
        void make_hearts();
        void render_hearts();
        void update_hearts(Player&player,Entity&entity);
        void set_hearts(Player&player);
        void make_player();
//        bool colideexit();
        void ClearScreen();
        ~PlayScreen();


    const int SIZE=16;
    SDL_Color color[2] = {{255,255,255},{255,0,0}};

        public:
        bool animLeft=false;
        bool animUp=false;

        Player*player;
        AudioManager* mAudioMgr;
        InputManager*mInput=NULL;

        Dungeon*dungeon;

        Animation*mAnimation;
                //hearts
        Texture*heart;
        Heart_obj *hearts[3];
};

#endif // PLAYSCREEN_H
