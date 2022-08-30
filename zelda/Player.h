#ifndef PLAYER_H
#define PLAYER_H
#include "Texture.h"

class Player
{
    public:
        Player();
        Player(const int x,const int y,const int w,const int h);
        void Update();
        void Render();
        void Render_hit();
        void RenderFlipped();
        virtual ~Player();
        Texture*player;
        SDL_Rect gSpriteClip;
        int x;
        int y;
        int width;
        int hight;
        float Scalex=3.5;
        float Scaley=3.5;
        //colision rect
        SDL_Rect rect;
        bool canRender=true;
        bool flip=false;
        //hitbox
        int hitboxWidth=15;
        int hitboxHeight=70;
        SDL_Rect lefthitbox;
        SDL_Rect righthitbox;
        SDL_Rect uphitbox;
        SDL_Rect downhitbox;
        int c=0;
        int wait_time=0;
        bool is_hit=false;
        int health=6;
};

#endif // PLAYER_H
