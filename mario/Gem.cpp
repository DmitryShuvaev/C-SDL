#include "Gem.h"

Gem::Gem()
{
    //ctor
    mgemTimeanim=Timer::Instance();
    startanim=true;
        //gemSpriteClips
    SDL_Rect gemSpriteClips[2][4];
    int dy=0;
    int dx=0;
    for(int y=0;y<2;y++)
    {

    for(int x=0;x<4;x++)
    {
        gemSpriteClips[y][x].x=dx;
        gemSpriteClips[y][x].y=dy;
        gemSpriteClips[y][x].w=16;
        gemSpriteClips[y][x].h=16;
        dx+=16;
    }
        dx=0;
        dy+=16;
    }
    int randx=rand()%4;
    int randy=rand()%2;
gemSpriteClip=gemSpriteClips[randy][randx];
}

Gem::~Gem()
{
    //dtor
 mgemTimeanim = NULL;
}
void Gem::gemAnimation(int &y)
{
 mgemAnimationTimer += mgemTimeanim->DeltaTime();
 if(mgemAnimationTimer/0.3f>=1)
 {
     //mgemAnimationTimer=0.0f;
     startanim=false;
 }else
 {
  y-=3;
 }
}
