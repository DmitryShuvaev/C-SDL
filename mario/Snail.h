#ifndef SNAIL_H
#define SNAIL_H
#include "Texture.h"
#include "Timer.h"
class Snail
{
    public:
        enum SNAILSTATES{idleS,moving,chasing};
        enum DIRECTION{left,right};
        Snail();
        virtual ~Snail();

        void Update();
        void Render();
        void RenderFlipped();
        //bool checkLeftCollisions(float &dx,TileMap & mTileMap);
        //bool checkRightCollisions(float &dx,TileMap & mTileMap);
        void movinAnimation(float t);
        void idleAnimation();
        float Scalex=5;
        float Scaley=5;
        float x;
        int y;
        int width;
        int hight;
        //Texture*character;
        SDL_Rect gSpriteClip;
        //SDL_Rect gSpriteClips[6];
       SNAILSTATES state;
       DIRECTION movingDirection;
        float mAnimationTimer=0.2f;
        int count=0;
        bool renderflipp=false;
int movingDuration=0;
float movingTimer=0;
        Timer* mTimer;
        Timer* mTimer2;
        bool consumad=false;
};

#endif // SNAIL_H
